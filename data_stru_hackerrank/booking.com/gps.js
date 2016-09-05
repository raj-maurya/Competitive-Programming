function processData(input) {
    //Enter your code here
    var json = JSON.parse(input);
   // console.log(json);
    var a = json.p1;
    var x1 = a.start[0];
    var y1 = a.start[1];
    var d1 = a.path[0];
   // console.log(a);
   // console.log(x1, y1, d1);
    var f = a.path;
    
    
    
    var b=json.p2;
    var x2 = b.start[0];
    var y2 = b.start[1];
    var d2 = b.path[0];
   // console.log (x2, y2, d2);
    
     var g = b.path;
    
    
    for (i=0; i<f.length; i++)
        {
            
            
             if (x1===x2 && y1===y2){
                 var t = [x2,y2];
                console.log(t.join(","), i);
                break;
            }
            
            else{
           // console.log(f.charAt(i));
            if(f.charAt(i)=="U"){
                y1 = y1+1;
            }
            else if(f.charAt(i)=="D"){
                y1 = y1-1;
            }
            else if(f.charAt(i)=="R"){
                x1 = x1+1;
            }
            else{
                x1 = x1-1;
            }
            
            
            
           // console.log(f.charAt(i));
             if(g.charAt(i)=="U"){
                y2 = y2+1;
            }
            else if(g.charAt(i)=="D"){
                y2 = y2-1;
            }
            else if(g.charAt(i)=="R"){
                x2 = x2+1;
            }
            else{
                x2 = x2-1;
            }
                 
            } 
           
        }
    

 //   var b=json.p2;
  //  var x2 = b.start[0];
  //  var y2 = b.start[1];
  //  var d2 = b.path[0];
   // console.log (x2, y2, d2);
    
   //  var g = b.path;
  /*  for (i=0; i<g.length; i++)
        {
           // console.log(f.charAt(i));
             if(g.charAt(i)=="U"){
                y2 = y2+1;
            }
            else if(g.charAt(i)=="D"){
                y2 = y2-1;
            }
            else if(g.charAt(i)=="R"){
                x2 = x2+1;
            }
            else{
                x2 = x2-1;
            }
        }
    console.log(x2, y2); */
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});

