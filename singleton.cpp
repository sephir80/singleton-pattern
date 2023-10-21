#include <map>
#include <string>

using std::string;

class GlobalCoffeeConfig
{
	private:
		std::map<string, string> coffeeState;
		GlobalCoffeeConfig() {} //private constructor
	public:
		// Remove ability to use the copy constructor
		GlobalCoffeeConfig(GlobalCoffeeConfig const&) = delete;
		// Remove ability top use the copy assignment operator
		GlobalCoffeeConfig& operator=(GlobalCoffeeConfig const&) = delete;

		// Provide a single, static method for retriving the singleton instance
		static GlobalCoffeeConfig& get()
		{
			static GlobalCoffeeConfig config;
			return config;
		}

		void setState(const string& key, const string& value)
		{
			coffeeState.insert({ key,value });
		}

		string getState(const string& key)
		{
			auto iterator = coffeeState.find(key);
			return iterator->second;
		}

};

int main()
{
	GlobalCoffeeConfig& configObj = GlobalCoffeeConfig::get();

	configObj.setState("COFFEE_STATUS", "ON");
	configObj.setState("COFFEE_HEALTH_URL", "./health");

	GlobalCoffeeConfig& configPippo = GlobalCoffeeConfig::get();

	printf("COFFEE_STATUS: %s\n", configPippo.getState("COFFEE_STATUS").c_str());
	printf("COFFEE_HEALTH_URL: %s\n", configPippo.getState("COFFEE_HEALTH_URL").c_str());

	return EXIT_SUCCESS;
}
