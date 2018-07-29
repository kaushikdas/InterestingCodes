#include <stdio.h>
#include <stdlib.h>

static int ztrlen(char s[])
{
  int l = 0;
  while (s[l]) l++;
  return l;
}

static void ztrcpy(char s[], char t[])
{
  int i = 0;
  while (s[i] = t[i]) i++;
}

static char* ztrdup(char *t)
{
  int l = ztrlen(t) + 1;
  char *s = (char*) malloc(l * sizeof(char));
  ztrcpy(s, t);
  return s;
}

// returns a new char string that is a substring of t
// from t[l] to t[r - 1]
static char* ztrsub(char *t, int l, int r)
{
  char *s = (char*)malloc((r - l + 1) * sizeof(char));
  for (register int i = l; i < r; ++i)
    s[i] = t[i];
  s[r] = '\0';
  return s;
}

struct KeyVal
{
  char *key; int val;
};

class IterableQ
{
  static const int MAX = 100;
  int f, r;
  KeyVal elm[MAX];

public:
  IterableQ() : f(0), r(0)
  {
    for (register int i = 0; i < MAX; ++i) elm[i].key = nullptr;
  };

  ~IterableQ()
  {
    flushQ();
  };

  void enQ(char *key, int val)
  {
    if (r == MAX) return;
    elm[r].key = ztrdup(key); elm[r].val = val; r++;
  };

  void deQ(KeyVal& out)
  {
    if (r == f) return;
    out.key = elm[f].key; out.val = elm[f].val;
    elm[f++].key = nullptr;
    if (r == f) r = f = 0;
  };

  void iterateQ()
  {
    for (register int t = f; t < r; ++t) 
      printf("  (%s, %d)\n", elm[t].key, elm[t].val);
  };

  void flushQ()
  {
    for (register int i = 0; i < MAX; ++i) {
      if (elm[i].key) {
        free(elm[i].key); elm[i].key = nullptr;
      }
    }
    f = r = 0;
  };
};

static const int R = 26;
static const int MAX_KEY_LEN = 100;

struct Nd
{
  int val;        // val of (key, val) pair 
  bool isKey;     // if the trie node is a key end
  Nd* next[R];    // list of links 

  Nd() : val(0), isKey(false)
  {
    // Initialize links to null
    for (register int i = 0; i < R; ++i) next[i] = nullptr;
  };

  ~Nd()
  {
    for (register int i = 0; i < R; ++i) {
      if (next[i] != nullptr) {
        delete next[i]; next[i] = nullptr;
      }
    }
  };
};

class Trie
{
  Nd *root; // root of trie
  int sz;   // trie size (number of unique keys in the trie)

  // temporary variables
  char *key;
  int val;
  int currentKeyLen;

  void setSearchKey(char *key)
  {
    this->key = key; currentKeyLen = ztrlen(key);
  };

  Nd* add(Nd *x, int d)
  {
    if (x == nullptr) x = new Nd();
    if (d == currentKeyLen) {
      x->val = val;
      if (!x->isKey) { // earlier this was not a key
        x->isKey = true; sz++;
      }
      return x;
    }
    char c = key[d] - 'a';
    x->next[c] = add(x->next[c], d + 1);
    return x;
  };

  Nd* search(Nd *x, int d)
  {
    if (x == nullptr) return nullptr;
    if (d == currentKeyLen) return x;
    char c = key[d] - 'a';
    return search(x->next[c], d + 1);
  };

  Nd* remove(Nd *x, int d)
  {
    if (x == nullptr) return nullptr;
    if (d == currentKeyLen) {
      if (x->isKey) {
        x->isKey = false; sz--;
      }
      else {
        printf("  <TRIE_INFO> "
               "remove - key \"%s\" is not found!\n", key);
      }
    }
    else {
      char c = key[d] - 'a';
      if (x->next[c])
        x->next[c] = remove(x->next[c], d + 1);
      else
        printf("  <TRIE_INFO> "
               "remove - key \"%s\" is not found!\n", key);
    }

    // remove subtrie rooted at x if it is completely empty
    if (x->isKey) return x;
    for (char c = 0; c < R; ++c)
      if (x->next[c] != nullptr)
        return x;

    delete x;
    return nullptr;
  };

  // IMPORTANT: prefix MUST be large enough be to hold the
  // largest key present in the trie
  // results: out param
  void collect(Nd *x, char *prefix, IterableQ& results)
  {
    if (x == nullptr) return;
    if (x->isKey) results.enQ(prefix, x->val);
    int l = ztrlen(prefix);
    for (char c = 0; c < R; ++c) {
      if (x->next[c]) {
        // append 'a' + c to prefix (prefix MUST be large enough
        // to accomodate the largest key present in the trie)
        prefix[l] = 'a' + c; prefix[l + 1] = '\0';
        collect(x->next[c], prefix, results);
        // reset prefix to as received
        prefix[l] = '\0';
      }
    }
  };

  int longestPrefix(Nd *x, int d, int prefixLen)
  {
    if (x == nullptr) return prefixLen;
    if (x->isKey) prefixLen = d;
    if (d == currentKeyLen) return prefixLen;
    char c = key[d] - 'a';
    return longestPrefix(x->next[c], d + 1, prefixLen);
  };

public:
  Trie() { root = nullptr; sz = 0; };

  ~Trie() { delete root; sz = 0; };

  // Inserts (key, val) to trie, overwriting the old value
  // with new value if the key already exists 
  void add(char *key, int val)
  {
    if (key == nullptr) {
      printf("  <TRIE_EXCEPTION> add - key is null!\n");
      return;
    }

    this->key = key; currentKeyLen = ztrlen(key); this->val = val;
    
    root = add(root, 0);
  };

  int search(char *key)
  {
    if (key == nullptr) {
      printf("  <TRIE_EXCEPTION> search - key is null!\n");
      return -1;
    }

    setSearchKey(key);
    Nd *x = search(root, 0);
    if (x == nullptr) {
      printf("  <TRIE_INFO> key %s not found.\n", key);
      return -1;
    }
    return x->val;
  };

  inline int size() const { return sz; };

  // Removes key if present
  void remove(char *key)
  {
    if (key == nullptr)
      printf("  <TRIE_EXCEPTION> remove - key is null!\n");
    setSearchKey(key);
    root = remove(root, 0);
  };

  void keys(IterableQ& results)
  {
    char prefix[MAX_KEY_LEN] = { 0 };
    keysWithPrefix(prefix, results);
  };

  // IMPORTANT: prefix MUST be large enough be to hold the
  // largest key present in the trie
  // results: out param
  void keysWithPrefix(char *prefix, IterableQ& results)
  {
    if (prefix == nullptr)
      printf("  <TRIE_EXCEPTION> keyWithPrefix - prefix is null!\n");
    setSearchKey(prefix);
    Nd *x = search(root, 0);
    // x is the nore till which the prefix exactly matches
    collect(x, prefix, results);
  };

  // Finds the key in the trie that longest prefix of the
  // input string s
  char* longestPrefix(char *s)
  {
    if (s == nullptr)
      printf("  <TRIE_EXCEPTION> longestPrefix - s is null!\n");
    setSearchKey(s);
    int l = longestPrefix(root, 0, -1);
    if (l == -1) return nullptr;
    else {
      char *t = ztrsub(s, 0, l);
      return t;
    }
  };
};

int main()
{
  printf("TRIE_MAIN\n");

  freopen("TrieInput.txt", "r", stdin);

  Trie trie;

  // add (key, val) pairs to trie 
  int n;
  scanf("%d", &n);
  char key[10][20] = { 0 };
  for (int i = 0; i < n; ++i) {
    scanf(" %[^\n]", key[i]);
    printf("[TRIE_MAIN] adding (%s, %d)...\n", key[i], i);
    trie.add(key[i], i);
  }
  printf("[TRIE_MAIN] added %d keys.\n", trie.size());
  // print the (key, val) pairs in the trie
  for (int i = 0; i < n; ++i) {
    int val = trie.search(key[i]);
    printf("[TRIE_MAIN] Found (%s, %d).\n", key[i], val);
  }

  printf("[TRIE_MAIN] Search a non-existing key \"false\"...\n");
  int val = trie.search("false");

  printf("[TRIE_MAIN] Key-Value pairs in the trie.\n");
  IterableQ results;
  trie.keys(results);
  results.iterateQ();
  results.flushQ();

  printf("[TRIE_MAIN] Removing keys \"sea\" and \"sha\" from the trie.\n");
  trie.remove("sea");
  trie.remove("sha");

  printf("[TRIE_MAIN] After removal trie has %d keys.\n", trie.size());
  printf("[TRIE_MAIN] Key-Value pairs in the trie after removal.\n");
  trie.keys(results);
  results.iterateQ();
  results.flushQ();

  char *t = trie.longestPrefix("shellsort");
  printf("[TRIE] Longest prefix of \"shellsort\" is \"%s\".\n", t);
  free(t);
  return 0;
}

/*
INPUT (TrieInput.txt)
---------------------
7
she
sells
sea
shells
by
the
seashore

OUTPUT
------
TRIE_MAIN
[TRIE_MAIN] adding (she, 0)...
[TRIE_MAIN] adding (sells, 1)...
[TRIE_MAIN] adding (sea, 2)...
[TRIE_MAIN] adding (shells, 3)...
[TRIE_MAIN] adding (by, 4)...
[TRIE_MAIN] adding (the, 5)...
[TRIE_MAIN] adding (seashore, 6)...
[TRIE_MAIN] added 7 keys.
[TRIE_MAIN] Found (she, 0).
[TRIE_MAIN] Found (sells, 1).
[TRIE_MAIN] Found (sea, 2).
[TRIE_MAIN] Found (shells, 3).
[TRIE_MAIN] Found (by, 4).
[TRIE_MAIN] Found (the, 5).
[TRIE_MAIN] Found (seashore, 6).
[TRIE_MAIN] Search a non-existing key "false"...
  <TRIE_INFO> key false not found.
[TRIE_MAIN] Key-Value pairs in the trie.
  (by, 4)
  (sea, 2)
  (seashore, 6)
  (sells, 1)
  (she, 0)
  (shells, 3)
  (the, 5)
[TRIE_MAIN] Removing keys "sea" and "sha" from the trie.
<TRIE_INFO> remove - key "sha" is not found!
[TRIE_MAIN] After removal trie has 6 keys.
[TRIE_MAIN] Key-Value pairs in the trie after removal.
  (by, 4)
  (seashore, 6)
  (sells, 1)
  (she, 0)
  (shells, 3)
  (the, 5)
[TRIE] Longest prefix of "shellsort" is "shells".
*/
