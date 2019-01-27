/**
 * we first print it and then recursively call DFS for its adjacent vertices. In topological sorting, we use a temporary stack. We don’t print the vertex immediately, we first recursively call topological sorting for all its adjacent vertices, then push it to a stack. Finally, print contents of stack. Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in stack. 
 */

let L = [];
let S = [];

function dfs_butdelayedpush(v,stack){
    // same as dfs but add to stack after all of its neigh pushed to stack


    v.is_visited = true;

    for (neigh in v.neighbours){
        if (neigh.is_visited)continue;// then skip this node
        
        tsutil(neigh,stack)
    }

    stack.push(v);
}


function TopologicalSort(GraphArr){
// input: G = contains all the nodes in the Graph
    let callStack = [];

    for (node in GraphArr){
        if (node.is_visited == false){
            dfs_butdelayedpush(node,callStack);
        }
    }
    // printing the stack
    print(callStack);
}