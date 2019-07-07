#include "crow_all.h"
 
int main()
{
    crow::SimpleApp app;
 
CROW_ROUTE(app, "/add_json")
.methods("POST"_method)([](const crow::request& req){
	    auto x = crow::json::load(req.body);
	    
	    if (!x)
	        return crow::response(400);
	    int sum = x["a"].i()+x["b"].i();
	    std::ostringstream os;
	    os << sum;

		crow::json::wvalue y;
    		y["resultado"] = os.str();

	    return crow::response{y.str()};
});
 
    app.port(18080).multithreaded().run();
}