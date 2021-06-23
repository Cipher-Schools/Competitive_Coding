package day9;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;

class TrieNode {

    boolean isEnd;
    char data;
    HashMap<Character, TrieNode> children;

    public TrieNode(char data) {
        this.data = data;
        isEnd = false;
        children = new HashMap<>();
    }
}

public class Trie {

    private TrieNode root;
    private int totalWords;

    public Trie() {
      root = new TrieNode((char) 48);
    }

    public int getTotalWords() {
        return totalWords;
    }

    public void addWord(String word) {
        if(addWordHelper(word, root)) {
            totalWords++;
        }
    }

    private boolean addWordHelper(String word, TrieNode node) {
        if(word.length() == 0) {
            node.isEnd = true;
            return true;
        }
        TrieNode child = node.children.get(word.charAt(0));
        if(child == null) {
            child = new TrieNode(word.charAt(0));
            node.children.put(word.charAt(0), child);
        }
       boolean isAdded = addWordHelper(word.substring(1), child);
       return   true;
    }

    private ArrayList<String> allWords(TrieNode node) {

        ArrayList<String> output = new ArrayList<>();

        if(node == null) {
            return  output;
        }

        if(node.isEnd) {
            output.add(node.data + "");
        }

        Set<Character> children = node.children.keySet();
        for(Character c : children) {
            ArrayList<String> childOutput = allWords(node.children.get(c));
            for(String word : childOutput) {
                output.add(node.data + word);
            }
        }
        return  output;
    }

    public ArrayList<String> allWords() {

        ArrayList<String> output = new ArrayList<>();

        Set<Character> children = root.children.keySet();

        for(Character c : children) {
            ArrayList<String> childOutput = allWords(root.children.get(c));
            output.addAll(childOutput);
        }
        return  output;
    }






}
