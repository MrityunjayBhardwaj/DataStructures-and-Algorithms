/**
 * Algorithm
 *      sort the edges by there weight
 *      pick the edges in assending order and check weather by joining the previously found edges doesnt give me a Cycle
 *      then after finding the edges joint all the disjoint edges.
 */

// import findCycle


// sort the edges
// pick the edges assending orderly and make it its own tree
// check if both the vertices inside the selected edges is inside any of the tree.
// then connect the tree.

function findNodeInStack(v,Stack){
    for ( node in Stack){
        if (v == node)return true;
    }
    return false;
}

function findCycle(v,recStack){
//input: 
        // v : current vertex/Node to process.
    v.is_visited = true;
    recStack.push(v);
    
    for (let i =0; i< v.neighbours.length;i++){
        let curr_neigh = curr_node.neighbours[i];

        if (!curr_neigh.is_visited){ // skip this iteration in-turn that node
        curr_neigh.comingfrom = curr_node;// register its parent. ( going to be useful for backtracking and other algorithms)

        findCycle(curr_node,recStack);

        }
        else if (findNodeInStack(v,recStack)){// if we found child is also an ansistor (by looking it in recStack)
            // then we found the cycle
            return true;

        }
    }

    recStack.pop();
    return false;
}


function Kruskal(G){
// G contain the entire Map/Graph
    let sortedEdgePairs = [];

    // extracting all the edge pairs from adjecency list
    sortedEdgePairs = sortEdgePairs(G);

    let shortestEdge=0;
    for(let i=0;i<sortedEdgePairs.length;i++){
        if( same_component(UnionSet,sortedEdgePairs[i].x,sortedEdgePairs.y) == false){
            union(sortedEdgePairs[i].x,sortedEdgePairs[i].y);
        }
    }
 }

/*
 Graph DataStructure

 Graph {
     this.id = 0;
     this.value = 0;
     this.commingfrom = vert;
     this.neighbourVerts = [];
     this.neihbourEdges = [];
 }
*/


let MinGraph = 0;

function edge(){
    this.Xvert = null;
    this.Yvert = null;
    this.weight = -1;
}

function sortEdgesGlobally(G){
//  return the sorted edges Array.

    let GlobalSortedWeights = [];
    let onlyweights = [];
    for(let vert in G){
        let ThisVertSortedWeights = SortByWeight(vert);// gives the index;
        let a = new edge();

        for(let i=0;i<ThisVertSortedWeights.length;i++){
            let currIndex = ThisVertSortedWeights[i];
            let newEdge = new edge();
            newEdge.weight = vert.neighbourEdge[currIndex];
            newEdge.Xvert  = vert;
            newEdge.Yvert  = vert.neighbourVerts[currIndex];

            GlobalSortedWeights.append(newEdge);
            onlyweights.append(newEdge.weight);
        }
    }

    // sorting the GlobalSortedWeights;
    let SortIndex = SortByWeight(onlyweights);

    let finalglobalsortedweights = [];

    // applying sort index
    for(let i =0;i<SortIndex.length;i++){
        finalglobalsortedweights.append(GlobalSortedWeights[SortIndex[i]]);
    }

    return finalglobalsortedweights;
}

function findVertex(G,v){
    for ( vert in G)if(v.id == vert.id)return vert;
}

function naiveKruskal(G){
// input G: Graph Array contain.
    // create a graph containg all the vertices in it

    // initializing MinGraph Array
    for (let i=0;i<G.length;i++){
    let cvert = G[i];
    cvert.neigbours = []; // empty the neighbours

    MinGraph.append(cvert);
    }

    let SortedEdges = sortEdgesGlobally(G);

    // select these sorted edges one by one and put it in the graph if and only of it doesnt create a cycle.
    
    for(let i=0;i<SortedEdges.length;i++){
        let curEdge = SortedEdges[i];
        let mingraphtmp = MinGraph; 
        // if by adding this curEdge doesnt give me cycle in my MinSpanning tree then add it!
            // adding this edge to our Minimum Spanning tree

            // find the vertex in our MinGraph
            let currMinGVertX = findVertex(mingraphtmp,curEdge.Xvert);
            let currMinGVertY = findVertex(mingraphtmp,curEdge.Yvert);

            currMinGVert.neighbourEdges.append(curEdge.weight);
            currMinGVert.neighbourVerts.append(currMinGVertY);

        if (findCycle(MinGraph,curEdge) == false){
            MinGraph = mingraphtmp
        }
    }
 }



 function goodKruskal(){
// using Union-find DataStructure

/* 
    select the smallest weight edge and add it into a set;

*/
 }