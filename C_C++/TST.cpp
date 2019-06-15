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
  char *s = (char*)malloc(l * sizeof(char));
  ztrcpy(s, t);
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

static const int MAX_KEY_LEN = 100;

struct Nd
{
  char c;                 // character stored in the node
  int val;                // val of (key, val) pair 
  bool isKey;             // if the node is a key end
  Nd *left, *right, *mid; // left, right and mid sub trees

  Nd() : c(0), val(0), isKey(false), 
         left(nullptr), right(nullptr), mid(nullptr) {};

  ~Nd()
  {
    if (left)   delete left;
    if (right)  delete right;
    if (mid)    delete mid;
  };
};

class TST
{
  Nd *root; // root of trie
  int sz;   // TST size (number of unique keys in the TST)

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
    char c = key[d];
    if (x == nullptr) {
      x = new Nd(); x->c = c;
    }
    if      (c < x->c)                x->left  = add(x->left,  d);
    else if (c > x->c)                x->right = add(x->right, d);
    else if (d < (currentKeyLen - 1)) x->mid   = add(x->mid,   d + 1);
    else {
      // key is ending here
      x->val = val; x->isKey = true; sz++;
    }
    return x;
  };

  Nd* search(Nd *x, int d)
  {
    if (x == nullptr) return nullptr;
    char c = key[d];
    if      (c < x->c)                return search(x->left,  d);
    else if (c > x->c)                return search(x->right, d);
    else if (d < (currentKeyLen - 1)) return search(x->mid,   d + 1);
    else                              return x;
  };

  // IMPORTANT: prefix MUST be large enough be to hold the
  // largest key present in the trie
  // results: out param
  void collect(Nd *x, char *prefix, IterableQ& results)
  {
    if (x == nullptr) return;

    // collect from left-sub-tree and for left sub-tree do not
    // include (append) cuurent node's character in prefix
    collect(x->left, prefix, results);

    // collect mid sub-tree and for that append current node's 
    // character to prefix
    int l = ztrlen(prefix);
    prefix[l] = x->c; prefix[l + 1] = '\0';
    if (x->isKey) {
      // current node to be collected
      results.enQ(prefix, x->val);
    }
    collect(x->mid, prefix, results);

    // Now collect right sub-tree and while doing so exclude
    // current node's character
    prefix[l] = '\0';
    collect(x->right, prefix, results);
  };

public:
  TST() { root = nullptr; sz = 0; };

  ~TST() { delete root; sz = 0; };

  // Inserts (key, val) to TST, overwriting the old value
  // with new value if the key already exists 
  void add(char *key, int val)
  {
    if (key == nullptr) {
      printf("  <TST_EXCEPTION> add - key is null!\n");
      return;
    }

    this->key = key; currentKeyLen = ztrlen(key); this->val = val;

    root = add(root, 0);
  };

  int search(char *key)
  {
    if (key == nullptr) {
      printf("  <TST_EXCEPTION> search - key is null!\n");
      return -1;
    }

    setSearchKey(key);
    Nd *x = search(root, 0);
    if (x == nullptr) {
      printf("  <TST_INFO> key %s not found.\n", key);
      return -1;
    }
    if (!x->isKey) {
      printf("  <TST_INFO> key %s not found.\n", key);
      return -1;
    }
    else {
      return x->val;
    }
  };

  inline int size() const { return sz; };

  void keys(IterableQ& results)
  {
    char prefix[MAX_KEY_LEN] = { 0 };
    collect(root, prefix, results);
  };

  // IMPORTANT: prefix MUST be large enough be to hold the
  // largest key present in the trie
  // results: out param
  void keysWithPrefix(char *prefix, IterableQ& results)
  {
    if (prefix == nullptr)
      printf("  <TST_EXCEPTION> keyWithPrefix - prefix is null!\n");
    setSearchKey(prefix);
    Nd *x = search(root, 0);
    // x is the node till which the prefix exactly matches
    if (x == nullptr) {
      printf("  <TST_INFO> key with prefix \"%s\" not found.\n",
             prefix);
      return;
    }
    collect(x->mid, prefix, results);
  };
};

int main()
{
  printf("TST_MAIN\n");

  freopen("TSTInput.txt", "r", stdin);

  TST tst;

  // add (key, val) pairs to tst 
  int n;
  scanf("%d", &n);
  char key[10][20] = { 0 };
  for (int i = 0; i < n; ++i) {
    scanf(" %[^\n]", key[i]);
    printf("[TST_MAIN] adding (%s, %d)...\n", key[i], i);
    tst.add(key[i], i);
  }
  printf("[TST_MAIN] added %d keys.\n", tst.size());
  // print the (key, val) pairs in the tst
  for (int i = 0; i < n; ++i) {
    int val = tst.search(key[i]);
    printf("[TST_MAIN] Found (%s, %d).\n", key[i], val);
  }

  printf("[TST_MAIN] Search a non-existing key \"abcd\"...\n");
  int val = tst.search("abcd");

  printf("[TST_MAIN] Key-Value pairs in the tst.\n");
  IterableQ results;
  tst.keys(results);
  results.iterateQ();
  results.flushQ();

  printf("[TST_MAIN] keys with prefix \"se\"...\n");
  char pre[MAX_KEY_LEN] = { 's', 'e' };
  tst.keysWithPrefix(pre, results);
  results.iterateQ();
  results.flushQ();

  return 0;
}

///:~

/*
INPUT (TSTInput.txt)
--------------------
8
she
shells
sea
sells
by
the
seashore
are

OUTPUT
------
TST_MAIN
[TST_MAIN] adding (she, 0)...
[TST_MAIN] adding (shells, 1)...
[TST_MAIN] adding (sea, 2)...
[TST_MAIN] adding (sells, 3)...
[TST_MAIN] adding (by, 4)...
[TST_MAIN] adding (the, 5)...
[TST_MAIN] adding (seashore, 6)...
[TST_MAIN] adding (are, 7)...
[TST_MAIN] added 8 keys.
[TST_MAIN] Found (she, 0).
[TST_MAIN] Found (shells, 1).
[TST_MAIN] Found (sea, 2).
[TST_MAIN] Found (sells, 3).
[TST_MAIN] Found (by, 4).
[TST_MAIN] Found (the, 5).
[TST_MAIN] Found (seashore, 6).
[TST_MAIN] Found (are, 7).
[TST_MAIN] Search a non-existing key "abcd"...
<TST_INFO> key abcd not found.
[TST_MAIN] Key-Value pairs in the tst.
(are, 7)
(by, 4)
(sea, 2)
(seashore, 6)
(sells, 3)
(she, 0)
(shells, 1)
(the, 5)
[TST_MAIN] keys with prefix "se"...
(sea, 2)
(seashore, 6)
(sells, 3)
*/
