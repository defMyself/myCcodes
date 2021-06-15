typedef struct entry 
{
	void *key;
	void *value;
	struct entry * next;
}*Entry;

#define newEntry() NEW(struct entry)
#define newEntryList(length) (Entry)malloc(length * sizeof(struct entry))

typedef struct hashMap *HashMap;
#define newHashMap() NEW(struct hashMap)

typedef int(*HashCode)(HashMap, void * key);

typedef Boolean(*Equal)(void * key1, void * key2);

typedef void(*Put)(HashMap hashMap, void * key, void * value);

typedef void * (*Get)(HashMap hashMap, void * key);

typedef Boolean(*Remove)(HashMap hashMap, void * key);

typedef void(*Clear)(HashMap hashMap);

typedef Boolean(*Exists)(HashMap hashMap, void * key);

typedef struct hashMap {
	int size;
	int listSize;
	HashCode hashCode;
	Equal equal;
	Entry list;
	Put put;
	Get get;
	Remove remove;
	Clear clear;
	Exists exists;
	Boolean autoAssign;
}*HashMap;

static int defaultHashCode(HashMap hashMap, void * key);

static Boolean defaultEqual(void * key1, void * key2);

static void defaultPut(HashMap hashMap, void * key, void * value);

static void * defaultGet(HashMap hashMap, void * key);

static Boolean defaultRemove(HashMap hashMap, void * key);

static Boolean defaultExists(HashMap hashMap, void * key);

static void defaultClear(HashMap hashMap);

HashMap createHashMap(HashCode hashCode, Equal equal);

static void resetHashMap(HashMap hashMap, int listSize);

int defaultHashCode(HashMap hashMap, let key)
{
	IN_STACK;
	string k = (string)key;
	unsigned long h = 0;
	while(*k) {
		h = (h<<4) + *k++;
		unsigned long g = h & 0xF0000000L;
		if(g) {
			h ^= g >> 24;
		}
		h &= ~g;
	}
	OUT_STATCK;
	return h % hashMap->listSize;
}

void resetHashMap(HashMap hashMap, int listSize) {
	if(listSize < 8) return;
	Entry tempList = newEntryList(hashMap->size);

	HashMapIterator iterator = createHashMapIterator(hashMap);
}