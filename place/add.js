function fun2(){
    let c=document.getElementById("total-budget");
    let b=document.getElementById("amount-deducted");
    let p=document.getElementById("show");
    let list_item=document.getElementById("uu");
    let list_item2=document.getElementById("llu");
  //   console.log(isNaN(q));
    if(isNaN(b.value)==true || b.value==""){
        alert("not a number");
      
    }
    
    else if(isNaN(b.value)==false && p.value!=""){
       let cost= document.getElementById("ans2");
       let third= document.getElementById("ans3");
       cost.innerText=parseInt(cost.innerText)+parseInt(b.value);
       let j=c.innerText;
       let a=10;
        c.value=c.value-b.value;
        
        document.getElementById("ans3").innerText=c.value;
       
        let make_li=document.createElement("li");
        make_li.appendChild(document.createTextNode(p.value));
        list_item.appendChild(make_li);
        
        let d=parseInt(third.innerText);
        if(d<a){
            cost.style.color="red";
            third.style.color="red";
        }
        else{
            cost.style.color="black";
            third.style.color="black";
        }
      // else{
           console.log(typeof(a));
           console.log(a);
           console.log(j);
           console.log(typeof(j));
           console.log(typeof(cost.innerText));
           console.log(typeof(d));
           console.log(d);
       
        let make2_li=document.createElement("li");
        make2_li.appendChild(document.createTextNode(b.value));
        list_item2.appendChild(make2_li);
    }

    b.value="";
    p.value="";
    //fun3();
}
