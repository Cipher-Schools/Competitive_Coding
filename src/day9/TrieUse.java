package day9;


public class TrieUse {


    public static void main(String[] args) {

        Trie trie = new Trie();

        trie.addWord("tea");
        trie.addWord("trend");
        trie.addWord("truck");
        trie.addWord("trunck");

        System.out.println(trie.getTotalWords());

        for(String s : trie.allWords()) {
            System.out.println(s);
        }

        trie.remove("truck");

    }
}
