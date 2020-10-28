var lengthOfLongestSubstring = function (s) {
  let pointer = 0;
  let letters = {};
  const window = [];
  let maxLen = 0;
  for (let i = 0; i < s.length; i++) {
    const letter = s[i];
    if (!letters[letter]) {
      letters[letter] = true;
    } else {
      while (letters[letter]) {
        let removed = window.shift();
        letters[removed] = false;
      }
    }
    window.push(letter);
    letters[letter] = true;
    if (window.length > maxLen) {
      maxLen = window.length;
    }
  }
  return maxLen;
};
