/** Algorithm
 *  select a vertex
 *  then select the smallest weighted child
 *  if that child if connected to our New MSTree doesnt creat a cycle then,
 *  call the function with this child repeat the process
 *   
 */

 function SortByWeight(Weights){
// return sortedIndex Configuration.
    let sortedIndex = [];
    let weightArr = Weights;

    for (let i=0;i<weightArr.length;i++){
        sortedIndex.push(i);
    } 

    // using Bubble sort
    for (let i=0;i<weightArr.length;i++){
        let wi = weightArr[i];

        for (let j=0;j<weightArr.length;j++){
            let wj= weightArr[j];
            if(wj < wi){// swap `em
                let tmp = wj;
                wj = wi;
                wi =tmp;

                // sorting the Index also 
                let tmpI = sortedIndex[j]
                sortedIndex[j] = sortedIndex[i];
                sortedIndex[j] = tmpI;

            }

        }

    }
    return sortedIndex
 }

 function primsMST(v,MSTree){
    
    MSTree.push(v);

    let sortedWeights = SortByWeight(v);


    // let smallestWeight = 1e10+5;// 10**10+5
    // for (let i=0;i<v.neighbours.length;i++){ let cweight = v.neighbours[i];
    //      if (cweight < smallestWeight )smallestWeight == cweight;
    // }

    for (let i=0;i<v.neighbours.length;i++){
        let curr_neigh = v.neighbours[sortedWeights[i]];
        if (findNodeInStack(v,MSTree))continue; // if that node is creating a cycle then dont add that node in our Tree

        // select the smallest weighted Node
        primsMST(curr_neigh,MSTree);
    }


 }