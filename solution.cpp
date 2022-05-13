#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol2196;
using namespace std;

/*takeaways
  - use a set to record which node has a parent
    - the root is the one who doesn't have a parent
  - use a hash table to record a node's children
  - build the tree recursively

*/

Node *Solution::_build(int val, unordered_map<int, pair<int, int>> children)
{
  if (!val)
    return nullptr;

  auto node = new Node(val);
  node->left = _build(children[val].first, children);
  node->right = _build(children[val].second, children);
  return node;
}

Node *Solution::build(vector<vector<int>> &desp)
{
  auto hasParent = unordered_set<int>();
  /* key is the parent; value is the pair of left and right child */
  auto children = unordered_map<int, pair<int, int>>();

  for (auto &d : desp)
  {
    int parent = d[0], child = d[1], isLeft = d[2];
    hasParent.insert(child);
    /* don't forget the parenthesis */
    (isLeft ? children[parent].first : children[parent].second) = child;
  }

  auto root = 0;
  for (auto &d : desp)
    if (!hasParent.count(d[0]))
    {
      root = d[0];
      break;
    }

  return _build(root, children);
}