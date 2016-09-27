$(function() {
    var json = {
        "people": {
            "person": [{
                "name": "Peter",
                "age": 43,
                "sex": "male"},
            {
                "name": "Zara",
                 "name": "Peter",
                "age": 65,
                "sex": "female"}
                ,
            {
                "name": "Zara",
                 "name": "Peter",
                "age": 65,
                "sex": "female"},
            {
                "name": "Zara",
                 "name": "Peter",
                "age": 65,
                "sex": "female"},
            {
               "name": "startups", 
               "name": "Peter",
               "name": "hackernews", 
               "name": "ycombinator",
           "pname":"pply to Y Combinator"}]
        }
    }
    
    var p=0;
    $.each(json.people.person, function(i, v) {
        if (v.name == "Peter") {
          console.log(v.pname);
          p++
         
        }
    });
    console.log(p);
});
