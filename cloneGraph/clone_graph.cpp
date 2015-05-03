/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;

        //key: orginal node, value: cloned node
        unordered_map<const UndirectedGraphNode*, UndirectedGraphNode *> copied;
        return clone(node, copied);
    }

    UndirectedGraphNode * clone(const UndirectedGraphNode *node,
                        unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> &copied){
        //递归出口，如果已经存在这个节点的键值对，则返回已经处理过的键对应的graph
        if(copied.find(node) != copied.end()) return copied[node];

        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label); //先填充数字
        copied[node] = new_node;    //记录已经处理过的节点

        for(auto nbr: node->neighbors)  //取出每一个邻接节点
            new_node->neighbors.push_back(clone(nbr, copied));  //递归，深度优先

        return new_node;    //添加完neighbors，返回上一层，并带回完全节点
    }
};
