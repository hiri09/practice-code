function check(){
    let v1=document.quiz.question1.value;
    let v2=document.quiz.question2.value;
    let v3=document.quiz.question3.value;
    let count=0;
    if(v1=="markup"){
        count++;
    }
    if(v2=="true"){
        count++;
    }
    if(v3=="img"){
        count++;
    }
    var message=["try hard","do well but need more hardwork","excellent my brother"];

    document.getElementById("after_submit").innerHTML="submitted";

    document.getElementById("messages").innerHTML=message[count-1];

    document.getElementById("number_correct").innerHTML=count;
}