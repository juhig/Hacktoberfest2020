import os
import sqlite3
import sys
TITLE = r"""
        ::    ::  ::::::::  ::::    ::  ::::::::  ::::::::::::  ::::::::  ::::    ::
       ::    ::  ::    ::  :::::   ::  ::        ::   ::   ::  ::    ::  :::::   ::
      ::    ::  ::    ::  :: ::   ::  ::        ::   ::   ::  ::    ::  :: ::   ::
     ::    ::  ::    ::  ::  ::  ::  ::        ::   ::   ::  ::    ::  ::  ::  ::
    ::::::::  ::::::::  ::   :: ::  ::  ::::  ::   ::   ::  ::::::::  ::   :: ::
   ::    ::  ::    ::  ::   :: ::  ::    ::  ::   ::   ::  ::    ::  ::   :: ::
  ::    ::  ::    ::  ::    ::::  ::    ::  ::   ::   ::  ::    ::  ::    ::::
 ::    ::  ::    ::  ::     :::  ::    ::  ::   ::   ::  ::    ::  ::     :::
::    ::  ::    ::  ::      ::  ::::::::  ::   ::   ::  ::    ::  ::      ::
"""

sys_windows = os.name == "nt"
conn = sqlite3.connect("words.db3")
cur = conn.cursor()


class Hangman:
    """HANGMAN !"""
    def __init__(self):
        self.letters = []
        self.difficulty = 0
        self.tries = 0
        self.total_tries = 0

    @staticmethod
    def clear():
        """clear terminal for windows (cmd) and unix"""
        if not sys_windows:
            os.system("clear")
        else:
            os.system("cls")

    def check_letter(self, letter, word):
        """check if letter inside hidden word"""
        if letter not in self.letters:
            if letter in word:
                return True
        return False

    @staticmethod
    def check_word(word, hidden):
        """check if hidden word is user provided word"""
        if word == hidden:
            return True
        return False

    def reset(self):
        """reset letters"""
        self.letters = []

    def victory(self):
        """print Victory or Defeat message at end of game."""
        tries_msg = ""
        vic_def = "Victory"
        if self.difficulty > 1:
            if self.tries - self.total_tries > 0:
                plural = 'tries' if self.total_tries - self.tries > 1 else 'try'
                tries_msg = f" in {self.tries - self.total_tries} {plural}"
            if self.tries == 0:
                vic_def = "Defeat"
        print(f"{vic_def}{tries_msg}!")
        self.menu()

    def menu(self):
        """EndGame menu."""
        restart = input("Restart ? (yes | no | !settings | Enter for exit...)\n>>")
        if restart == "yes":
            self.reset()
            self.clear()
            self.game()
        if restart == "!settings":
            self.settings()
            self.reset()
            self.clear()
            self.game()
        else:
            input("Goodbye! (press enter)")
            sys.exit(0)

    def get_tries(self, length):
        """Get tries by difficulty."""
        if self.difficulty == 2:
            if length > 8:
                self.tries = length
            else:
                self.tries = 8
        elif self.difficulty == 3:
            self.tries = 8
        else:
            self.tries = 1
        self.total_tries = self.tries

    def game(self):
        """HangMan game !"""
        print(TITLE, "\n")
        word, length = cur.execute("SELECT * FROM words ORDER BY RANDOM() LIMIT 1;").fetchone()
        word_letters = set(word)
        hidden = list('_' * length)
        self.get_tries(length)
        while self.tries > 0 or self.difficulty == 1:
            print(f"\n{''.join(hidden)}")
            tries_left = ""
            if self.difficulty > 1:
                tries_left = f"(tries left: {self.tries})"
            user_input = input(f"Input a letter or a word {tries_left}:\n>> ")
            if len(user_input) > 1:
                if self.check_word(user_input, word):
                    return self.victory()
                break
            if len(user_input) == 1:
                if user_input in self.letters:
                    print(f"You already send this letter!\n"
                          f"already tried: {', '.join(self.letters)}\n")
                elif self.check_letter(user_input, word_letters):
                    word_letters.remove(user_input)
                    indexes = [int(i) for i, letter in enumerate(word) if letter == user_input]
                    for index in indexes:
                        hidden[index] = user_input
                    if len(word_letters) == 0:
                        self.victory()
                    self.letters.append(user_input)
                else:
                    print("No such letter in the word\n")
                    self.letters.append(user_input)
                    self.tries -= 1
        return self.victory()

    def settings(self):
        """Set difficulty by user input."""
        choice = input("select difficulty :\n"
                       "1. EASY (unlimited tries)\n"
                       "2. MEDIUM (word length as tries [start at 8])\n"
                       "3. HARD (only 8 tries)\n"
                       "4. IMPOSSIBLE (only 1 tries hf)\n>>")
        if choice.isdigit():
            self.difficulty = int(choice)
        else:
            print("failed to find correct number set difficulty to medium...")
            self.difficulty = 2


hangman = Hangman()
hangman.settings()
hangman.game()
