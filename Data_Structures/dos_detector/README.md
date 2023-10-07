# DOS attack detector
## Objectives
- Learn how to implement a collision-managed hash table using chaining. 
- Learn how to use the types defined in *cstdint*.

## Description
A “Denial of Service” (DOS) attack consists of the attacking computer (or computers if coordinated) flooding a server (e.g. web, email, dns...) with access requests at such a speed that this server cannot serve anyone else (legitimate or not) and in extreme cases it can even fall.

Normally, servers inform the operating system of abnormal accesses using some “Log” utility of the system. A DOS attack detector will periodically trace these “Logs” looking for anomalous access patterns and blocking (“ban”) the addresses considered malicious in the firewall so they will no longer access the server.

Here we will simulate a DOS attack detector. The detector will periodically (every second) analyze the system Log (we abstract it as a sequence of entries time/ip address). In each cycle the detector will analyze, in a time window of 1 minute, how many times the same ip address was accessed to the server. If this number of times exceeds a threshold specified by the user, this ip address will be considered malicious and will be blocked (“banned”) on the firewall.

The detector will use two hash tables to store an access counter per active IP in the temporary window and another to keep the time of the first time an IP has been blocked. 

The design of the detector will be as follows:

```cpp
Algorithm DOS_detector(
    log:Log, //Array of pairs <Time, IP>
    maxAcc:Integer)//Max. num. of acc.
Local
    i:Integer //First unprocessed line of log.
    j:Integer //First line in current temporal window.
    c:HashTable[IP,Integer] //Save a counter by activeip.
Begin
    i ← 0
    j ← 0
while system::sleep(1) do //sleep 1 second.
    updateCounters(log, i, j, c, maxAcc)
end-while
end.Algorithm updateCounters(
    log:Log,//Array of pairs <Time, IP>
    Var i:Integer,//First unprocessed line of log.
    Var j:Integer,//First line in current temporal window.
    Var c:HashTable[IP, Integer],//Save a counter byactive ip
    maxAcc:Integer //Max. num. of acc. allowed.
)
Begin//update new accesses
    while log[i].time < system::now() do
        increment(log[i].ip, c)
        if nAcc(log[i].ip, c) >= maxAcc then
            system::banIP(log[i].ip])
        end-if
        i ← i + 1
    end-while//remove old accesses.
    while log[j].time < system::now()-60 do
        decrement(log[j].ip, c)– 1
        j ← j + 1
    end-while
end.
```

So, we will have to first implement the HashTable[K,V] type using strings to handle collisions and then using hashtables on the DOS detector.

## Tests
- Hash Table
- DOS Detector