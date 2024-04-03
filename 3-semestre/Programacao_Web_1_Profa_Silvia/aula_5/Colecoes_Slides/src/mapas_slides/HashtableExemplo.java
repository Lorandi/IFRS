/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mapas_slides;

import java.util.*;

public class HashtableExemplo {

    public static void main(String[] args) {
        Hashtable<String, Integer> mapTable = new Hashtable<>();
        mapTable.put("cod1", 1);
        mapTable.put("cod2", 2);
        mapTable.put("cod3", 3);
        Enumeration enumIter = mapTable.elements();
        while(enumIter.hasMoreElements()){
              Integer num = (Integer) enumIter.nextElement();    
              System.out.println(num);
        }
    }
}


