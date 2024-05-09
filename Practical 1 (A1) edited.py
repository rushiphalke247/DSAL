import array as arr

def acceptData(n):
    l1 = []
    while len(l1) < n:
        t = input("Enter telephone no of client: ")
        if len(t) == 10 and t.isdigit():
            l1.append(t)
        else:
            print("\nInvalid telephone no:")
    return l1

def linearProbing(l1):
    n = len(l1)
    t1 = []
    for i in range(0, n):
        t1.append(0)
    coll = 0
    ht = arr.array('i', t1)
    for i in l1:
        t = int(i) % n
        coll = 1
        if ht[t] == 0:
            ht[t] = int(i)
            print('inserted key:', i, ' at:', t, "with complexity:", "O(", str(coll), ")")
            coll = 0
        else:
            print("Collision at index: ", t, " for ", i)
            print("Use probing:")
            cnt = t
            while True:
                cnt = (cnt + 1) % n
                if cnt == t:
                    print("Collision cannot be resolved or overflow")
                    break
                else:
                    if ht[cnt] == 0:
                        ht[cnt] = int(i)
                        print('inserted key:', i, ' at:', cnt, "with complexity:", "O(", str(coll + 1), ")")
                        coll = 0
                        break
                    else:
                        coll += 1
    return ht

def search(key, ht):
    print("_" * 60)
    print("Linear Probing:")
    coll = 1
    n = len(ht)
    t = int(key) % n
    if ht[t] == int(key):
        print("_" * 60)
        print("Telephone no found at", t, "Complexity: O(1)", " key:", key)
    else:
        print("Search Using Linear Probing")
        coll = 1
        cnt = t
        while True:
            cnt = (cnt + 1) % n
            if cnt == t:
                print("_" * 60)
                print("Telephone no not found:", key)
                print("Telephone not found Complexity:O(", str(coll + 1), ") key:", key)
                break
            else:
                if ht[cnt] == int(key):
                    print("_" * 60)
                    print("Telephone no found at", cnt, "Complexity:O(", str(coll + 1), ") key:", key)
                    break
                else:
                    coll += 1

# Prompt the user to enter the number of clients
n = int(input("Enter the number of clients: "))

# Get the list of telephone numbers from the user
l1 = acceptData(n)

# Perform linear probing and create the hash table
ht = linearProbing(l1)

# Prompt the user to enter telephone numbers to search for
while True:
    key = input("Enter a telephone number to search (or 'q' to quit): ")
    if key.lower() == 'q':
        break
    search(key, ht)