class Solution {
  List<String> wordSubsets(List<String> words1, List<String> words2) {
    
  // Function to count character frequencies in a word
  List<int> countFrequency(String word) {
    List<int> count = List.filled(26, 0); // Initialize the list with 0s for each letter a-z
    for (int i = 0; i < word.length; i++) {
      count[word.codeUnitAt(i) - 'a'.codeUnitAt(0)]++;
    }
    return count;
  }

  // Determine the maximum frequencies needed for each character from words2
  List<int> maxFreq = List.filled(26, 0);
  for (String word in words2) {
    List<int> wordFreq = countFrequency(word);
    for (int i = 0; i < 26; i++) {
      maxFreq[i] = max(maxFreq[i], wordFreq[i]);
    }
  }

  // Check each word in words1 against the max frequencies
  List<String> result = [];
  for (String word in words1) {
    List<int> wordFreq = countFrequency(word);
    bool isUniversal = true;
    for (int i = 0; i < 26; i++) {
      if (wordFreq[i] < maxFreq[i]) {
        isUniversal = false;
        break;
      }
    }
    if (isUniversal) {
      result.add(word);
    }
  }

  return result;
}

// Example usage


  
}