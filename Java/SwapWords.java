import java.util.Scanner;

public class SwapWords {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter a sentence: ");
        String sentence = scanner.nextLine();
        
        System.out.print("Enter the first word to swap: ");
        String word1 = scanner.next();
        
        System.out.print("Enter the second word to swap: ");
        String word2 = scanner.next();
        
        // Split the sentence into words
        String[] words = sentence.split(" ");
        
        // Create a StringBuilder to build the new sentence
        StringBuilder newSentence = new StringBuilder();
        
        // Iterate through the words and swap the specified words
        for (String word : words) {
            if (word.equals(word1)) {
                newSentence.append(word2).append(" ");
            } else if (word.equals(word2)) {
                newSentence.append(word1).append(" ");
            } else {
                newSentence.append(word).append(" ");
            }
        }
        
        // Remove the trailing space and print the new sentence
        String result = newSentence.toString().trim();
        System.out.println("Swapped sentence: " + result);
        
        scanner.close();
    }
}
