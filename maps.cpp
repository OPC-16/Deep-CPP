/* ---- maps ----
 *      Author >_ OPC
 */
#include <iostream>
#include <map> //this is sorted, it uses self-balancing binary search tree (red-black tree)
#include <unordered_map>   //it uses hash table, generally faster than regular map, but still it depends on compiler and number of 
                           //elements in the map

struct cityRecord {
   std::string name;
   uint64_t population;
   double latitude, longitude;
};

//implementing hash function for cityRecord type
namespace std {
   template<>
   struct hash<cityRecord> {
      size_t operator () (const cityRecord& key)  {
         return hash<std::string>()(key.name);  //it first constructs it and then call it
      }
   };
} //std namespace

int main() {
   //template args are 'key' and 'value'
   std::map<std::string, cityRecord> cityMap;
   //this is how we populate the map
   cityMap["burrow"] = cityRecord { "The Burrow", 8, 8.3, 8.3};
   cityMap["hollow"] = cityRecord { "Godric's Hollow", 3, 8.3, 8.3};
   cityMap["manor"] = cityRecord { "Malfoy Manor", 3, 8.3, 8.3};
   cityMap["hogsmeade"] = cityRecord { "Hogsmeade", 123541, 8.3, 8.3};

   //To retrive the data -
   cityRecord& hogsmeadeData = cityMap["hogsmeade"];
   int pop = hogsmeadeData.population;

   //unordered_map
   std::unordered_map<std::string, cityRecord> cityMapUnorderedType;

   //as keys are hashed in unordered_map we have to implement a hash func for cityRecord type as c++ stl doesn't have hash func for such 
   //type
   std::unordered_map<cityRecord, uint32_t> foundedMap;  //the value here is year founded
   foundedMap[cityRecord{ "Malfoy Manor", 3, 8.3, 8.3 }] = 1650;
   //retriving data
   uint32_t malfoyYearFounded = foundedMap[cityRecord{ "Malfoy Manor", 3, 8.3, 8.3 }];

   //it is important to note that the index operator [] isn't used for special purposes, it only inserts the data specificed inside it
   //so if we put a city name which is not previously declared, [] will construct an emplaced object with default values of variables
   //used in declaration of struct, e.g. -
   cityRecord& honeydukeData = cityMap["honeyduke"];  //this will create an empty obj with 'name' with empty str and int, double with
                                                      //unallocated memory
   //now we can use this empty value obj to put in desired data -
   honeydukeData.name = "Honey Dukes";
   honeydukeData.population = 12345;
   honeydukeData.latitude = 2.3, honeydukeData.longitude = 2.3;

   //same above can be achieved like this 
   /*
   cityRecord honeydukeData;
   honeydukeData.name = "Honey Dukes";
   honeydukeData.population = 12345;
   honeydukeData.latitude = 2.3, honeydukeData.longitude = 2.3;
   cityMap["honeyduke"] = honeydukeData;
   */
   //BUT this method is slow as it first creates obj on main's stack, fills it with data and then copies this obj to map's stack


   //but if the map is const so inserting new data is not possible as const version of [] does not exist
   //so to just return the elements from map and not insert them we use '.at' operator
   cityRecord& hogsmeadeConstData = cityMap.at("hogsmeade");
   std::string someName = hogsmeadeConstData.name;
   //if we use .at for the data which is not present in map, code will crash, so data should be in map for .at
   //we can use .find to first see if the data is present in map and then assign it with .at, eg -
   if (cityMap.find("hogsmeade") != cityMap.end()) {
      const cityRecord& hogsmeadeData2 = cityMap.at("hogsmeade");
   }


   //iterating thr the map (it is slow than vector and usually we don't iterate thr maps)
   for (auto& [name, city] : cityMap) {
      std::cout << name << "\n population: " << city.population << std::endl;
   }

   //for removing an element
   cityMap.erase("hollow");   //put the key in it
} //function-main
