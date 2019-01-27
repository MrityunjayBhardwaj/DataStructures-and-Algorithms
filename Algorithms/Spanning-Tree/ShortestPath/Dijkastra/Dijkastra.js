/*
 Graph {
     this.id = num;
     this.value = x;
     this.neighVerts = [];
     this.neighEdges = [];
 }

*/

function getsmallestVertIndex(distarr,is_visited){
    let b = 0;
    let index = -1;
    for (let i=0;i<distarr.length;i++){
        if (b > distarr[i] && !is_visited[i]){b = distarr[i];index = i}
    }
    return index;
}

function Dijkastra(G,v){

// G : Array of Graph Vertices according to there ids

    let Solution = [];
    let is_visited = [];
    let distance = [];
    let parents = [];

    // initializing Solution and VertexArray.
    for(let i=0;i<vertNum;i++){
        // Solution.append(-1);
        distance.append(Infinity);
        parents.append(null);
        is_visited.append(false);
    }


    while( vertexArray.length > 0){
        let getindex = getsmallestVertIndex(distance,is_visited);// NOTE: could use a priority Q but then i have to recalculate it in every iteration
        let cvert = G[getindex];

        
        Solution.append(cvert);

        for ( let i=0;i<cvert.neighbourVerts.length;i++){
            let cneigh = cvert.neighbourVerts[i]
            let calculatedWeight = (distance[cvert.id] + cvert.neighbourEdges[i]);

            if (distance[cneigh.id] > calculatedWeight){// check if this new weight is better then previously calculated weight
                distance[cneigh.id] = calculatedWeight; 
                parents[cneigh.id]  = cvert;
            }
        }
        is_visited[cvert.id] = 0;
    }

}