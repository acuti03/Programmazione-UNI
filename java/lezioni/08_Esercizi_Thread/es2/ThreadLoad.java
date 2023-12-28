package es2;

import java.util.*;

public class ThreadLoad extends Thread{
    
    private HashMap<Integer, Double> threadLoad;

    public ThreadLoad(){
        threadLoad = new HashMap<>(10);
    }

    /**
     * inserisce l'informazione di cpu load
     * riguardante il thread con id 
     * @param threadId
     * @param cpuLoad
    **/
    public synchronized void setThreadLoad(int threadId, double cpuLoad){
        threadLoad.put(threadId, cpuLoad); 
    }

    /**
     * restituisce il threadId con il piu alto cpuLoad
     * @return
    **/
    public synchronized Integer getMaxThreadId(){
        Map.Entry<Integer, Double> max = null;

        for(Map.Entry<Integer, Double> entry : threadLoad.entrySet()){
            if(max == null || entry.getValue().compareTo(max.getValue()) > 0){
                max = entry;
            }
        }

        if (max == null) return null;
        
        return max.getKey();
    }

    /**
     * restituisce il cpu load del corrispondente
     * thread id
     * @param threadId
     * @return 
    **/
    public synchronized Double getCpuLoad(Integer threadId){

        if(threadId == null) return null;

        return threadLoad.get(threadId);
    }
}
