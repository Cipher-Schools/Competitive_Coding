package day15;

import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

public class Twitter {

    static int timeStamp = 0;

    public Map<Integer, User> userMap;

    class TweetNode {

        public int tweetId;
        public int time;
        public TweetNode next;

        public TweetNode(int tweetId) {
            this.tweetId = tweetId;
            time = timeStamp;
            timeStamp++;
            next = null;
        }
    }

     class User {
        public int userId;
        public Set<Integer> followed;
        public TweetNode tweetHead;

        public User(int userId) {
            this.userId = userId;
            followed = new HashSet<>();
            follow(userId);
            tweetHead = null;
        }

        public void post(int tweetId) {
            TweetNode tweet = new TweetNode(tweetId);
            tweet.next = tweetHead;
            tweetHead = tweet;
        }

        public void follow(int followeeId) {
            followed.add(followeeId);
        }

        public void unfollow(int followeeId) {
            followed.remove(followeeId);
        }
    }



    /** Initialize your data structure here. */
    public Twitter() {
        userMap = new HashMap<Integer, User>();
    }

    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        if(!userMap.containsKey(userId)) {
            User user = new User(userId);
            userMap.put(userId, user);
        }
        User user = userMap.get(userId);
        user.post(tweetId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> result = new LinkedList<>();

        if(!userMap.containsKey(userId)) {
            System.out.println(userId);
            return result;
        }

        User user = userMap.get(userId);
        Set<Integer> followedUsers =  user.followed;

        PriorityQueue<TweetNode> maxHeap = new PriorityQueue<TweetNode>(followedUsers.size(),
                (tweet1, tweet2) -> (tweet2.time - tweet1.time));

        for(int id : followedUsers) {
            User u = userMap.get(id);
            TweetNode head = u.tweetHead;

            if(head != null) {
                maxHeap.add(head);
            }
        }

        int count = 0;
        while(!maxHeap.isEmpty() && count < 10) {
            TweetNode tweet = maxHeap.poll();
            result.add(tweet.tweetId);
            count++;
            if(tweet.next != null) {
                maxHeap.add(tweet.next);
            }
        }

        return result;


    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        if(!userMap.containsKey(followerId)) {
            User u = new User(followerId);
            userMap.put(followerId, u);
        }

        if(!userMap.containsKey(followeeId)) {
            User u = new User(followeeId);
            userMap.put(followeeId, u);
        }

        User user = userMap.get(followerId);
        user.follow(followeeId);

    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {

        if(!userMap.containsKey(followerId)) {
            User u = new User(followerId);
            userMap.put(followerId, u);
        }

        if(!userMap.containsKey(followeeId)) {
            User u = new User(followeeId);
            userMap.put(followeeId, u);
        }

        User user = userMap.get(followerId);
        user.unfollow(followeeId);
    }

    public static void main(String[] args) {
        Twitter twitter = new Twitter();
        twitter.postTweet(1, 5);
        twitter.getNewsFeed(1);

        twitter.follow(1,2);

    }

}