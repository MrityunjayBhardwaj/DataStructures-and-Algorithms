
var UnionTree = [];

function UnionFind(){
    this.parent = null; // parent of current node
    this.treeSize = 0; // size of the tree.
    this.value = -1; // value of the node.
}

function find(node){
// Alogithm: find the root of tree containing elements by walking up to 
// the parent pointers untill there is null. return te label of the root node

// return the name of the set
let thisnode = -1;
let a = 0;
    for ( cnode in UnionTree ){
        if (cnode.id == node.id)thisnode = cnode;
    }

    // search its root node
    while(true){
        if (thisnode.parent == null)return thisnode;
        thisnode = thisnode.parent;
    }

}

function union(tree1,tree2){
    // add the smaller of the 2 sets to the bigger set/tree
    // Assuming tree1 and tree2 are the root node of the tree;

    let biggertree,
        smallertree;

    if (tree1.treeSize > tree2.treeSize){
        biggertree = tree1
        smallertree = tree2
    }
    else{
        biggertree = tree2
        smallertree = tree1
    }

    // joining the trees
    smallertree.parent = biggertree
}

function same_component(unionset,v1,v2){
    return (find(v1) === find(v2)); // if both vertices lies in the same set then return true;
}