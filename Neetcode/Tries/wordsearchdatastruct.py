# https://neetcode.io/problems/design-word-search-data-structure
# https://leetcode.com/problems/design-add-and-search-words-data-structure/


class WordDictionary:

    def __init__(self):
        self.root = {"*": False}

    def addWord(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr:
                curr[c] = {"*": False}
            curr = curr[c]
        curr["*"] = True

    def search(self, word: str) -> bool:
        def helper(curr, subword):
            for i, c in enumerate(subword):
                if c == ".":
                    for k in curr:
                        if k != "*" and helper(curr[k], subword[i + 1 :]):
                            return True
                    return False
                elif c not in curr:
                    return False
                curr = curr[c]
            return curr["*"]

        curr = self.root
        return helper(curr, word)
