package com.mongodb;


import java.util.*;
import java.util.function.Predicate;

public class Ff {


    public static void main(String[] args) {
        int n = 345;
        System.out.println(Integer.toBinaryString(n));
        n = n& (~(1<<4));
        System.out.println(Integer.toBinaryString(n));

    }
}
