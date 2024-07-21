# https://neetcode.io/problems/implement-prefix-tree
# https://leetcode.com/problems/implement-trie-prefix-tree/


class Trie:
    def __init__(self):
        self.root = {"*": False}

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr:
                curr[c] = {"*": False}
            curr = curr[c]
        curr["*"] = True

    def search(self, word: str) -> bool:
        curr = self.root
        for c in word:
            if c not in curr:
                return False
            curr = curr[c]
        return curr["*"]

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        for c in prefix:
            if c not in curr:
                return False
            curr = curr[c]
        return True
