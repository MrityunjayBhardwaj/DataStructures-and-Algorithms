main();

function main(){
    let knapsack_size = 7;
    let ourobjects = [[1,1],[3,4],[4,5],[5,7]];

    knapsack(ourobjects,knapsack_size);
}


function knapsack(objs,space){
    /*
        inputs:
            objs => array of objects that we need to add to our knapsack,
            this array need to contain 1) size/weight/space 2) value of each object

            space => total size of our knapsack
        output:
            table of best possible configuration of our object inside a given space.
     */

    const valueMatrix = Array(objs.length+1).fill(null).map(() => Array(space+1).fill(null));


    // Initializing to zeros
    for(let i=0;i<valueMatrix.length;i++){
        valueMatrix[i][0] = 0;
    }

    for(let j=0;j<valueMatrix[0].length;j++){
        valueMatrix[0][j] = 0;
    }


    // looping over objs
    for(let i=1;i<valueMatrix.length;i++){
        let curr_obj      = null || objs[i-1];// this variable contains current object's [1]size as well as [0]value
        // looping over size of our knapsack
        for(let j=1;j<valueMatrix[0].length;j++) {

            if(curr_obj[0] > j){
                valueMatrix[i][j]=valueMatrix[i-1][j]
            }
            else{
                valueMatrix[i][j]=Math.max(
                        valueMatrix[i-1][j],
                        curr_obj[1] + valueMatrix[i-1][j-curr_obj[0]]
                );
            }

        }
    }

        return valueMatrix
}
