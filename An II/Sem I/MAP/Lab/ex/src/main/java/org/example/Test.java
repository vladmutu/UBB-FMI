package org.example;

class AA<E,T>{
    private E e;
    private T t;
    public void setValueE(E e){
        this.e = e;
    }
    public void setValueT(T t){
        this.t = t;
    }
    public E getValue(){
        return e;
    }
    public T getValue1(){
        return t;
    }
}


public class Test { 
    public static void main(String[] args) { 
        AA bb = new AA<Integer, String>(); 
        bb.setValueE(1010); 
        bb.setValueE("asfd"); 
        System.out.println(bb.getValue()+" "+ bb.getValue1());
    } 
}


