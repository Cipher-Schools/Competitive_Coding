package day19;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * @author amgarg
 */
class TrieNode {
    boolean isTerminal;
    char data;
    HashMap<Character, TrieNode> children;
    int freq;

    TrieNode(char data) {
        this.data = data;
        isTerminal = false;
        freq = 1;
        children = new HashMap<>();
    }
}

public class Trie {

    TrieNode root;
    int numWords;

    public Trie() {

        root = new TrieNode('\0');
        root.freq = 0;
    }

    public int size() {
        return numWords;
    }

    public boolean isEmpty() {
        return size() == 0;
    }


    private static boolean addHelper(String word, TrieNode node) {
        if (word.length() == 0) {
            if (node.isTerminal) {
                return false;
            }
            node.isTerminal = true;
            return true;
        }
        TrieNode child = node.children.get(word.charAt(0));
        if (child == null) {
            child = new TrieNode(word.charAt(0));
            node.children.put(word.charAt(0), child);
        } else {
            child.freq++;
        }

        return addHelper(word.substring(1), child);
    }

    public void add(String word) {
        if (addHelper(word, root)) {
            numWords++;
        }
    }




    private static ArrayList<String> allWords(TrieNode node) {
        ArrayList<String> output = new ArrayList<>();
        if (node == null) {
            return output;
        }
        if (node.isTerminal) {
            output.add(node.data + "");
        }

        for (Character c: node.children.keySet()) {
            ArrayList<String> childOutput = allWords(node.children.get(c));
            for (String s: childOutput) {
                output.add(node.data + s);
            }
        }
        return output;
    }

    public ArrayList<String> allWords() {
        ArrayList<String> output = new ArrayList<>();
        for (Character c: root.children.keySet()) {
            ArrayList<String> childOutput = allWords(root.children.get(c));
            output.addAll(childOutput);
        }
        return output;
    }




    public boolean hasWord(String word) {
        TrieNode currentNode = root;
        for (int i = 0; i < word.length(); i++) {
            TrieNode child = currentNode.children.get(word.charAt(i));
            if (child == null) {
                return false;
            }
            currentNode = child;
        }
        return currentNode.isTerminal;
    }


    public static void main(String[] args) {
        Trie t = new Trie();
		t.add("a");
        t.add("abc");
        t.add("abcd");



        for (String s: t.allWords()) {
            System.out.println(s);
        }
    }
}