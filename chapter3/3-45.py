"""3.45:
Give an algorithm for finding an ordered word pair 
(e.g. “New York”) occurring with the greatest frequency in a 
given webpage. Which data structures would you use? 
Optimize both time and space.
"""

""" HASH TABLE
    - You can use a hashtable for this by:
        - Scan the web page word by word except the first
        - take the pair formed by the previous word + the current word
        - use that pair as a key in the hash table where you store frequency of that pair
        - if the entry is is not alrady in the hash table, store it with a value of 1
        - if it is there, increment the current value by 1
        - return the greatest frequency seen
    - Optimization: 
        - Complexity: N = number of words in a text
        - Time: O(N), you only iterate over each word once
        - Space: O(N), worst case is every word is distinct so you have no repeated pairs
"""

""" TRIE
    - You can store the text in a trie and save the number of occurences in the leaf node
    - iterate through the text letter in O(n) time, using two word pointers
        - pointer word1 and pointer word2
        - they point to the position in a trie of the currentword and the concantentation of the current with the last word
    - Advantages:
        - no parameters have to be pre-defined 
        - uses relatively little memory

"""

class Trie:

    def __init__(self, parent=None):
        self.parent = parent
        self.children = {}
        self.n = 0

    def add(self, c):
        return self.children.setdefault(c, Trie(self))

    def letter(self, child):
        for c in self.children:
            if self.children[c] == child:
                return c
        return None

    def spell(self):
        if self.parent:
            return self.parent.spell() + self.parent.letter(self)
        return ''

def wrap(text):
    """iterates through text, yielding lowercase letter or single ' '"""
    inword = False
    for c in text:
        c = c.lower()
        if ord(c) >= ord('a') and ord(c) <= ord('z'):
            yield c
            inword = True
        else:
            if inword:
                yield ' '
            inword = False
    if inword:
        yield ' '

def pairmax(text):
    """finds the word pair with maximum occurrence"""
    root = word2 = Trie()
    best = word1 = None
    for c in wrap(text):
        if c == ' ':
            if word1:
                word2.n += 1
                if best is None or word2.n > best.n:
                    best = word2
                word2 = word1.add(' ')
                word1 = root
            else:
                word1 = root
                word2 = word2.add(' ')
        else:
            word2 = word2.add(c)
            if word1:
                word1 = word1.add(c)
    return best.spell(), best.n


if __name__ == '__main__':
    import urllib2, sys

    urls = sys.argv[1:]
    if not urls:
        urls = ['http://www.rfc-editor.org/rfc/rfc19%02d.txt' % i for i in range(30, 40)]

    for url in urls:
        word, n = pairmax(urllib2.urlopen(url).read())
        sys.stdout.write('%s : %dx "%s"\n' %(url, n, word))