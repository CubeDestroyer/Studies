
package com.company;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class Main {
    private static TreeMap<String, Integer> map = new TreeMap<>();
    private  static Scanner sc;
    private static final String path = "f.txt";
    public static void main(String[] args) throws IOException {

        sc = new Scanner(new File(path), StandardCharsets.UTF_8);
        readData();
        printfMap();

    }

    private static void readData() throws IOException {
        String a = "";
        while (sc.hasNext()) {
            a = sc.next();

            map.putIfAbsent(a.replaceAll("[^A-Za-zА-Яа-я0-9]", ""), 1);
        }
        sc.close();

        sc = new Scanner(new File(path), StandardCharsets.UTF_8);

        while (sc.hasNext()) {
            a = sc.next();
            a= a.replaceAll("[^A-Za-zА-Яа-я0-9]", "");
            map.put(a, map.get(a) + 1);

        }


    }

    private static void printfMap() {

        Set<String> ks =map.keySet();
        String s = "";
        Integer v;
        Iterator<String> it = ks.iterator();

        while (it.hasNext()) {
            s=it.next();
            v= map.get(s);
            System.out.printf("%14s || %2d\n", s,v);
        }

    }
}
