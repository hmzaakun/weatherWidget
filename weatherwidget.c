#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>
#include <curl/curl.h>
#include <string.h>
#include <gtk/gtk.h>

// Make them global

GtkWidget	*window;
GtkWidget	*fixed1;
GtkWidget	*entry1;
GtkWidget	*button1;
GtkWidget	*label1;
GtkWidget	*label2;
GtkWidget	*label3;
GtkWidget	*label4;
GtkWidget	*label5;
GtkWidget	*label6;
GtkWidget	*label7;
GtkWidget	*label8;
GtkWidget	*label9;
GtkWidget	*label10;
GtkWidget	*respons1;
GtkWidget	*respons2;
GtkWidget	*respons3;
GtkWidget	*respons4;
GtkWidget	*respons5;
GtkWidget	*respons6;
GtkWidget	*respons7;
GtkWidget	*respons8;
GtkBuilder	*builder;

GtkWidget	*label1b;
GtkWidget	*label2b; 
GtkWidget	*label3b; 
GtkWidget	*label4b; 
GtkWidget	*label5b; 
GtkWidget	*respons1b;
GtkWidget	*respons2b;
GtkWidget	*respons3b;
GtkWidget	*respons4b;
GtkWidget	*respons5b;

GtkWidget	*label1c;
GtkWidget	*label2c;
GtkWidget	*label3c;
GtkWidget	*label4c;




struct Vetement {
			char haut[100];
			char corps [100];
			char bas [100];
			char chaussures [100];
			char accessoires[100];
    };



char* substr(char* src, int start, int end){

    int srctaille= strlen(src);
    int temptaille = srctaille;
    int restaille = end;

    char *temp = malloc(sizeof(char)*temptaille);
    char *dest  = malloc(sizeof(char)*srctaille);

    strcpy(temp, ((src)+start));
    strncpy(dest, temp, end);
    if (dest != NULL) {
        strncpy(dest, src + start, end - start);
        dest[end - start] = '\0';
    }


    free(temp);
    return dest;
}


int main(int argc, char *argv[]) {
	
	FILE *fp;
	char buffer[1024];
	struct json_object *parsed_json;
	struct json_object *request;
	struct json_object *current;
	struct json_object *query;
	struct json_object *localtime;
	struct json_object *location;
	struct json_object *name;
	struct json_object *country;
	struct json_object *temperature ;
	struct json_object *weather_descriptions;
	struct json_object *weather_icons;
	struct json_object *humidity;
	struct json_object *wind_speed;
	struct json_object *precip;
	
	struct Vetement vetement1;
	
	
	
    char resultat[255] = "http://api.weatherstack.com/current?access_key=09572acfb5e03232bb3f64cba1df588f&query=paris";
  
    
    
	
	CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, resultat);

        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        /* create an output file and prepare to write the response */
        FILE *output_file = fopen("test.json", "w");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, output_file);
		
		
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %sn", 
                curl_easy_strerror(res));
        }

        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(output_file);
    }
	
	
	
	
	///////////////////* parsing json */////////////////////

	fp = fopen("test.json","r");
	fread(buffer, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "location", &location);
	json_object_object_get_ex(parsed_json, "current", &current);
	
	
	json_object_object_get_ex(location, "localtime", &localtime);
	json_object_object_get_ex(location, "name", &name);
	json_object_object_get_ex(location, "country", &country);
	
	json_object_object_get_ex(current, "temperature", &temperature);
	json_object_object_get_ex(current, "weather_descriptions", &weather_descriptions);
	json_object_object_get_ex(current, "weather_icons", &weather_icons);
	json_object_object_get_ex(current, "humidity", &humidity);
	json_object_object_get_ex(current, "wind_speed", &wind_speed);
	json_object_object_get_ex(current, "precip", &precip);

	gtk_init(&argc, &argv); // init Gtk

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("main.glade");
 
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

        gtk_builder_connect_signals(builder, NULL);

	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	entry1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
	button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
	label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
	label2 = GTK_WIDGET(gtk_builder_get_object(builder, "label2"));
	label3 = GTK_WIDGET(gtk_builder_get_object(builder, "label3"));
	label4 = GTK_WIDGET(gtk_builder_get_object(builder, "label4"));
	label5 = GTK_WIDGET(gtk_builder_get_object(builder, "label5"));
	label6 = GTK_WIDGET(gtk_builder_get_object(builder, "label6"));
	label7 = GTK_WIDGET(gtk_builder_get_object(builder, "label7"));
	label8 = GTK_WIDGET(gtk_builder_get_object(builder, "label8"));
	label9 = GTK_WIDGET(gtk_builder_get_object(builder, "label9"));
	label10 = GTK_WIDGET(gtk_builder_get_object(builder, "label10"));
	respons1 = GTK_WIDGET(gtk_builder_get_object(builder, "respons1"));
	respons2 = GTK_WIDGET(gtk_builder_get_object(builder, "respons2"));
	respons3 = GTK_WIDGET(gtk_builder_get_object(builder, "respons3"));
	respons4 = GTK_WIDGET(gtk_builder_get_object(builder, "respons4"));
	respons5 = GTK_WIDGET(gtk_builder_get_object(builder, "respons5"));
	respons6 = GTK_WIDGET(gtk_builder_get_object(builder, "respons6"));
	respons7 = GTK_WIDGET(gtk_builder_get_object(builder, "respons7"));
	respons8 = GTK_WIDGET(gtk_builder_get_object(builder, "respons8"));
	
	label1b = GTK_WIDGET(gtk_builder_get_object(builder, "label1b"));
	label2b = GTK_WIDGET(gtk_builder_get_object(builder, "label2b"));
	label3b = GTK_WIDGET(gtk_builder_get_object(builder, "label3b"));
	label4b = GTK_WIDGET(gtk_builder_get_object(builder, "label4b"));
	label5b = GTK_WIDGET(gtk_builder_get_object(builder, "label5b"));
	respons1b = GTK_WIDGET(gtk_builder_get_object(builder, "respons1b"));
	respons2b = GTK_WIDGET(gtk_builder_get_object(builder, "respons2b"));
	respons3b = GTK_WIDGET(gtk_builder_get_object(builder, "respons3b"));
	respons4b = GTK_WIDGET(gtk_builder_get_object(builder, "respons4b"));
	respons5b = GTK_WIDGET(gtk_builder_get_object(builder, "respons5b"));
	
	label1c = GTK_WIDGET(gtk_builder_get_object(builder, "label1c"));
	label2c = GTK_WIDGET(gtk_builder_get_object(builder, "label2c"));
	label3c = GTK_WIDGET(gtk_builder_get_object(builder, "label3c"));
	label4c = GTK_WIDGET(gtk_builder_get_object(builder, "label4c"));
	
	
	gtk_label_set_text (GTK_LABEL(respons6), (const gchar* ) json_object_get_string(country));
	gtk_label_set_text (GTK_LABEL(respons1), (const gchar* ) json_object_get_string(name));
	gtk_label_set_text (GTK_LABEL(respons2), (const gchar* ) json_object_get_string(temperature));
	gtk_label_set_text (GTK_LABEL(respons3), (const gchar* ) json_object_get_string(localtime));
	gtk_label_set_text (GTK_LABEL(respons4), (const gchar* ) json_object_get_string(json_object_array_get_idx(weather_descriptions, 0)));
	gtk_label_set_text (GTK_LABEL(respons5), (const gchar* ) json_object_get_string(humidity));
	gtk_label_set_text (GTK_LABEL(respons7), (const gchar* ) json_object_get_string(wind_speed));
	gtk_label_set_text (GTK_LABEL(respons8), (const gchar* ) json_object_get_string(precip));
	
	
				if(json_object_get_int(temperature) >= 20 ){
		
					strcpy(vetement1.corps,"t-shirt 👕");
					strcpy(vetement1.bas,"jeans 👖");
					strcpy(vetement1.chaussures,"shoes 👟");
					
					
					gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
					gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
					gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
					

					}else if(json_object_get_int(temperature) >= 25 ){
				
					strcpy(vetement1.corps,"t-shirt 👕");
					strcpy(vetement1.bas,"shorts 🩳");
					strcpy(vetement1.chaussures,"sandal 🩴");
					strcpy(vetement1.accessoires,"sunglasses 🕶️");
					
					gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
					gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
					gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
					gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
					
					}
					else if(json_object_get_int(temperature) >= 20 && json_object_get_int(wind_speed) >= 25 ){
				
					strcpy(vetement1.corps,"vest 🧑‍💼");
					strcpy(vetement1.bas,"jeans 👖");
					strcpy(vetement1.chaussures,"shoes 👟");
					strcpy(vetement1.accessoires,"sunglasses 🕶️");
					
					gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
					gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
					gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
					gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
					
					}
					
					else if(json_object_get_int(temperature) >= 15 && json_object_get_int(temperature) < 20 ){
                
                            strcpy(vetement1.haut,"not necessary at the moment");
                            strcpy(vetement1.corps,"vest 🧑‍💼");
                            strcpy(vetement1.bas,"jeans 👖");
                            strcpy(vetement1.chaussures,"shoes 👟");
                            strcpy(vetement1.accessoires,"not necessary at the moment");
                            
                            gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
                            gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
                            gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
                            gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
                            gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
                            
                            

                    }
					
					else if(json_object_get_int(temperature) >= 10 && json_object_get_int(temperature) <= 15 && json_object_get_double(precip) >= 0.10 ){
					
					strcpy(vetement1.corps,"coat 🧥");
					strcpy(vetement1.bas,"jeans 👖");
					strcpy(vetement1.chaussures,"shoes 👟");
					strcpy(vetement1.accessoires,"umbrella ☂️");
					
					gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
					gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
					gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
					gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);

					}else if(json_object_get_int(temperature) >= 10 && json_object_get_int(temperature) <= 15  ){
					
					strcpy(vetement1.corps,"coat 🧥");
					strcpy(vetement1.bas,"jeans 👖");
					strcpy(vetement1.chaussures,"shoes 👟");
					
					gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
					gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
					gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);

					}
					
					else if(json_object_get_int(temperature) >= 5 && json_object_get_int(temperature) <= 10  ){
					
					strcpy(vetement1.corps,"coat 🧥");
					strcpy(vetement1.bas,"jeans 👖");
					strcpy(vetement1.chaussures,"shoes 👟");
					
					gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
					gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
					gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
					

					}
					else if(json_object_get_int(temperature) >=0 && json_object_get_int(temperature) <= 5 && json_object_get_double(precip) > 0.10){
					
					
					strcpy(vetement1.corps,"coat 🧥");
					strcpy(vetement1.bas,"jeans 👖");
					strcpy(vetement1.chaussures,"shoes 👟");
					strcpy(vetement1.accessoires,"umbrella ☂️");
					
					gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
					gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
					gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
					gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
					
					}
					
					
					
					else if(json_object_get_int(temperature) >=0 && json_object_get_int(temperature) <= 5   ){
					strcpy(vetement1.haut,"beanie 🥷");
					strcpy(vetement1.corps,"coat 🧥");
					strcpy(vetement1.bas,"jeans 👖");
					strcpy(vetement1.chaussures,"shoes 👟");
					strcpy(vetement1.accessoires,"gloves 🧤");
					
					gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
					gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
					gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
					gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
					gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);


					}
					else if(json_object_get_int(temperature) >=0 && json_object_get_int(temperature) <= 5  && json_object_get_double(precip) > 0.3 ){
					strcpy(vetement1.haut,"beanie 🥷");
					strcpy(vetement1.corps,"coat 🧥");
					strcpy(vetement1.bas,"jeans 👖");
					strcpy(vetement1.chaussures,"shoes 👟");
					strcpy(vetement1.accessoires,"umbrella ☂️");
					
					gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
					gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
					gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
					gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
					gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);


					}
					
					
					else if(json_object_get_int(temperature) <= 0  ){
					strcpy(vetement1.haut,"beanie 🥷");
					strcpy(vetement1.corps,"puffy jacket 🧥");
					strcpy(vetement1.bas,"pants 👖");
					strcpy(vetement1.chaussures,"boots 🥾");
					strcpy(vetement1.accessoires,"gloves 🧤");
					
					gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
					gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
					gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
					gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
					gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);



					}
					else if(json_object_get_int(temperature) <= 0 && json_object_get_double(precip) > 0.2 ){
					strcpy(vetement1.haut,"beanie 🥷");
					strcpy(vetement1.corps,"puffy jacket 🧥");
					strcpy(vetement1.bas,"pants 👖");
					strcpy(vetement1.chaussures,"boots 🥾");
					strcpy(vetement1.accessoires,"umbrella ☂️");
					
					
					gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
					gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
					gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
					gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
					gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
					

					}
	
	
	
				char src[255];
				strcpy(src,json_object_get_string(localtime));
		   
				char *dest;
				dest = substr(src, 5, 7);
				
				
				if(strcmp(dest,"01")==0){
							
							gtk_label_set_text (GTK_LABEL(label1c), "We must plant the garlic 🧄");
							
							}
							else if(strcmp(dest,"02")==0){
								
							gtk_label_set_text (GTK_LABEL(label1c), "We must plant the garlic 🧄");
							gtk_label_set_text (GTK_LABEL(label2c), "You have to plant the zucchini 🥒");
							
							}
							else if(strcmp(dest,"03")==0){
								
							gtk_label_set_text (GTK_LABEL(label1c), "We must plant the garlic 🧄");
							gtk_label_set_text (GTK_LABEL(label2c), "You have to plant the zucchini 🥒");
							gtk_label_set_text (GTK_LABEL(label3c), "We must plant the potatoes 🥔");
						   
							}
							else if(strcmp(dest,"04")==0){
								
							gtk_label_set_text (GTK_LABEL(label1c), "You have to plant the zucchini 🥒");
							gtk_label_set_text (GTK_LABEL(label2c), "You have to plant the beans 🌱");
							gtk_label_set_text (GTK_LABEL(label3c), "You have to plant the tomatoes 🍅");
							gtk_label_set_text (GTK_LABEL(label4c), "We must plant the potatoes 🥔");
							}
							else if(strcmp(dest,"05")==0){
								
							gtk_label_set_text (GTK_LABEL(label1c), "You have to plant the beans 🌱");
							gtk_label_set_text (GTK_LABEL(label2c), "You have to plant the tomatoes 🍅");
							gtk_label_set_text (GTK_LABEL(label3c), "We must plant the potatoes 🥔");	
							  
							  
							}
							else if(strcmp(dest,"06")==0){
								
							gtk_label_set_text (GTK_LABEL(label1c), "You have to plant the tomatoes 🥔");
							gtk_label_set_text (GTK_LABEL(label2c), "It's time to harvest garlic 🧄");
						   

							}
							else if(strcmp(dest,"07")==0){
							
							gtk_label_set_text (GTK_LABEL(label1c), "Time to harvest the potatoes 🥔");
							gtk_label_set_text (GTK_LABEL(label2c), "It's time to harvest garlic 🧄");
							gtk_label_set_text (GTK_LABEL(label3c), "It's time to harvest tomatoes 🍅");
							gtk_label_set_text (GTK_LABEL(label4c), "It's time to harvest the beans 🌱");
						   
							}
							else if(strcmp(dest,"08")==0){
								
							gtk_label_set_text (GTK_LABEL(label1c), "Time to harvest the potatoes 🥔");
							gtk_label_set_text (GTK_LABEL(label2c), "It's time to harvest garlic 🧄");
							gtk_label_set_text (GTK_LABEL(label3c), "It's time to harvest tomatoes 🍅");
							gtk_label_set_text (GTK_LABEL(label4c), "It's time to harvest the beans 🌱");
						   
							
							}
							else if(strcmp(dest,"09")==0){
								
							gtk_label_set_text (GTK_LABEL(label1c), "Time to harvest the potatoes 🥔");
							gtk_label_set_text (GTK_LABEL(label2c), "It's time to harvest tomatoes 🍅");
							gtk_label_set_text (GTK_LABEL(label3c), "It's time to harvest the beans 🌱");
						   
							
							}
							else if(strcmp(dest,"10")==0){
							
							gtk_label_set_text (GTK_LABEL(label1c), "Time to harvest the beans 🌱");
							gtk_label_set_text (GTK_LABEL(label2c), "It's time to harvest the zucchini 🥒");
						   
						   
							}
							else if(strcmp(dest,"11")==0){
						   
							
							}
							else if(strcmp(dest,"12")==0){
						   
							
					}
					free(dest);
	
	
	
	
	
	/* GdkColor color; // default background color
			color.red = 0xcccc;
			color.green = 0xcccc;
			color.blue = 0xcccc;
			gtk_widget_modify_bg(GTK_WIDGET(window), GTK_STATE_NORMAL, &color); */
	
	gtk_widget_show(window);

	gtk_main();
	
	return EXIT_SUCCESS;
	}

			
			
void	on_entry1_changed(GtkEntry *e) {
		char tmp[128];
		sprintf(tmp, "%s", gtk_entry_get_text(e));
		gtk_label_set_text (GTK_LABEL(label7), (const gchar* ) tmp);
		}
			
void	on_button1_clicked (GtkButton *b,GtkEntry *entry1) {
			
			
			FILE *fp;
			char buffer[1024];
			struct json_object *parsed_json;
			struct json_object *request;
			struct json_object *current;
			struct json_object *query;
			struct json_object *localtime;
			struct json_object *location;
			struct json_object *name;
			struct json_object *country;
			struct json_object *temperature ;
			struct json_object *weather_descriptions;
			struct json_object *weather_icons;
			struct json_object *humidity;
			struct json_object *wind_speed;
			struct json_object *precip;
			
			struct Vetement vetement1;
	
			
			
			
			const gchar *tmp; 
			tmp=gtk_label_get_text(GTK_LABEL(label7));
			char link[255]="http://api.weatherstack.com/current?access_key=09572acfb5e03232bb3f64cba1df588f&query=";
			
			strcat(link,tmp);
			
			CURL *curl;
			CURLcode res;

			curl = curl_easy_init();
			if(curl) {
				curl_easy_setopt(curl, CURLOPT_URL, link);

				curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

				FILE *output_file = fopen("test.json", "w");
				curl_easy_setopt(curl, CURLOPT_WRITEDATA, output_file);
				
				
				res = curl_easy_perform(curl);

				if(res != CURLE_OK) {
					fprintf(stderr, "curl_easy_perform() failed: %sn", 
						curl_easy_strerror(res));
				}

				curl_easy_cleanup(curl);
			fclose(output_file);
		}
		
		
				///////////////////* parsing json */////////////////////

				fp = fopen("test.json","r");
				fread(buffer, 1024, 1, fp);
				fclose(fp);

				parsed_json = json_tokener_parse(buffer);

				json_object_object_get_ex(parsed_json, "location", &location);
				json_object_object_get_ex(parsed_json, "current", &current);
				
				
				json_object_object_get_ex(location, "localtime", &localtime);
				json_object_object_get_ex(location, "name", &name);
				json_object_object_get_ex(location, "country", &country);
				
				json_object_object_get_ex(current, "temperature", &temperature);
				json_object_object_get_ex(current, "weather_descriptions", &weather_descriptions);
				json_object_object_get_ex(current, "weather_icons", &weather_icons);
				json_object_object_get_ex(current, "humidity", &humidity);
				json_object_object_get_ex(current, "wind_speed", &wind_speed);
				json_object_object_get_ex(current, "precip", &precip);
				
				
				
				gtk_label_set_text (GTK_LABEL(respons6), (const gchar* ) json_object_get_string(country));
				gtk_label_set_text (GTK_LABEL(respons1), (const gchar* ) json_object_get_string(name));
				gtk_label_set_text (GTK_LABEL(respons2), (const gchar* ) json_object_get_string(temperature));
				gtk_label_set_text (GTK_LABEL(respons3), (const gchar* ) json_object_get_string(localtime));
				gtk_label_set_text (GTK_LABEL(respons4), (const gchar* ) json_object_get_string(json_object_array_get_idx(weather_descriptions, 0)));
				gtk_label_set_text (GTK_LABEL(respons5), (const gchar* ) json_object_get_string(humidity));
				gtk_label_set_text (GTK_LABEL(respons7), (const gchar* ) json_object_get_string(wind_speed));
				gtk_label_set_text (GTK_LABEL(respons8), (const gchar* ) json_object_get_string(precip));
				
				
				
				if(json_object_get_int(temperature) >= 25 ){
				
							strcpy(vetement1.haut,"not necessary at the moment");
							strcpy(vetement1.corps,"t-shirt 👕");
							strcpy(vetement1.bas,"shorts 🩳");
							strcpy(vetement1.chaussures,"sandal 🩴");
							strcpy(vetement1.accessoires,"sunglasses 🕶️");
							
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
							
							}
							else if(json_object_get_int(temperature) >=0 && json_object_get_int(temperature) <= 5  && json_object_get_double(precip) > 0.3 ){
							strcpy(vetement1.haut,"beanie 🥷");
							strcpy(vetement1.corps,"coat 🧥");
							strcpy(vetement1.bas,"jeans 👖");
							strcpy(vetement1.chaussures,"shoes 👟");
							strcpy(vetement1.accessoires,"umbrella ☂️");
							
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);


							}
								
							else if(json_object_get_int(temperature) >=0 && json_object_get_int(temperature) <= 5   ){
							strcpy(vetement1.haut,"beanie 🥷");
							strcpy(vetement1.corps,"coat 🧥");
							strcpy(vetement1.bas,"jeans 👖");
							strcpy(vetement1.chaussures,"shoes 👟");
							strcpy(vetement1.accessoires,"gloves 🧤");
							
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);


							}
							
							else if(json_object_get_int(temperature) >= 20 &&  json_object_get_int(temperature) < 25 && json_object_get_int(wind_speed) >= 25 ){
						
							strcpy(vetement1.haut,"not necessary at the moment");
							strcpy(vetement1.corps,"vest 🧑‍💼");
							strcpy(vetement1.bas,"jeans 👖");
							strcpy(vetement1.chaussures,"shoes 👟");
							strcpy(vetement1.accessoires,"sunglasses 🕶️");
							
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
							
							}
							else if(json_object_get_int(temperature) >= 20 && json_object_get_int(temperature) < 25 ){
				
							strcpy(vetement1.haut,"not necessary at the moment");
							strcpy(vetement1.corps,"t-shirt 👕");
							strcpy(vetement1.bas,"jeans 👖");
							strcpy(vetement1.chaussures,"shoes 👟");
							strcpy(vetement1.accessoires,"sunglasses 🕶️");
							
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
							
							

							}
							
							else if(json_object_get_int(temperature) >= 15 && json_object_get_int(temperature) < 20 ){
                
                            strcpy(vetement1.haut,"not necessary at the moment");
                            strcpy(vetement1.corps,"vest 🧑‍💼");
                            strcpy(vetement1.bas,"jeans 👖");
                            strcpy(vetement1.chaussures,"shoes 👟");
                            strcpy(vetement1.accessoires,"not necessary at the moment");
                            
                            gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
                            gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
                            gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
                            gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
                            gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
                            
                            

                            }
							
							else if(json_object_get_int(temperature) >= 10 && json_object_get_int(temperature) <= 15 && json_object_get_double(precip) >= 0.10 ){
							
							strcpy(vetement1.haut,"not necessary at the moment");
							strcpy(vetement1.corps,"coat 🧥");
							strcpy(vetement1.bas,"jeans 👖");
							strcpy(vetement1.chaussures,"shoes 👟");
							strcpy(vetement1.accessoires,"umbrella ☂️");
							
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);

							}else if(json_object_get_int(temperature) >= 10 && json_object_get_int(temperature) < 15  ){
							
							strcpy(vetement1.haut,"not necessary at the moment");
							strcpy(vetement1.corps,"coat 🧥");
							strcpy(vetement1.bas,"jeans 👖");
							strcpy(vetement1.chaussures,"shoes 👟");
							strcpy(vetement1.accessoires,"not necessary at the moment");
							
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);

							}else if(json_object_get_int(temperature) >= 5 && json_object_get_int(temperature) < 10 && json_object_get_double(precip) >= 0.10 ){
							strcpy(vetement1.haut,"not necessary at the moment");
							strcpy(vetement1.corps,"coat 🧥");
							strcpy(vetement1.bas,"jeans 👖");
							strcpy(vetement1.chaussures,"shoes 👟");
							strcpy(vetement1.accessoires,"umbrella ☂️");
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
							

							}
							else if(json_object_get_int(temperature) >= 5 && json_object_get_int(temperature) <= 10  ){
							
							strcpy(vetement1.haut,"not necessary at the moment");
							strcpy(vetement1.corps,"coat 🧥");
							strcpy(vetement1.bas,"jeans 👖");
							strcpy(vetement1.chaussures,"shoes 👟");
							strcpy(vetement1.accessoires,"not necessary at the moment");
							
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
							
							

							}
							
							else if(json_object_get_int(temperature) >= 5 && json_object_get_int(temperature) <= 10 && json_object_get_double(precip) >= 0.10 ){
							
							strcpy(vetement1.haut,"not necessary at the moment");
							strcpy(vetement1.corps,"coat 🧥");
							strcpy(vetement1.bas,"jeans 👖");
							strcpy(vetement1.chaussures,"shoes 👟");
							strcpy(vetement1.accessoires,"umbrella ☂️");
							
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
							

							}
							else if(json_object_get_int(temperature) >=0 && json_object_get_int(temperature) <= 5 && json_object_get_double(precip) > 0.10){
							
							strcpy(vetement1.haut,"not necessary at the moment");
							strcpy(vetement1.corps,"coat 🧥");
							strcpy(vetement1.bas,"jeans 👖");
							strcpy(vetement1.chaussures,"shoes 👟");
							strcpy(vetement1.accessoires,"umbrella ☂️");
							
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
							
							}
							
							
						
							
							
							else if(json_object_get_int(temperature) <= 0  ){
							strcpy(vetement1.haut,"beanie 🥷");
							strcpy(vetement1.corps,"puffy jacket 🧥");
							strcpy(vetement1.bas,"pants 👖");
							strcpy(vetement1.chaussures,"boots 🥾");
							strcpy(vetement1.accessoires,"gloves 🧤");
							
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);



							}
							else if(json_object_get_int(temperature) <= 0 && json_object_get_double(precip) > 0.2 ){
							strcpy(vetement1.haut,"beanie 🥷");
							strcpy(vetement1.corps,"puffy jacket 🧥");
							strcpy(vetement1.bas,"pants 👖");
							strcpy(vetement1.chaussures,"boots 🥾");
							strcpy(vetement1.accessoires,"umbrella ☂️");
							
							
							gtk_label_set_text (GTK_LABEL(respons1b), vetement1.haut);
							gtk_label_set_text (GTK_LABEL(respons2b), vetement1.corps);
							gtk_label_set_text (GTK_LABEL(respons3b), vetement1.bas);
							gtk_label_set_text (GTK_LABEL(respons4b), vetement1.chaussures);
							gtk_label_set_text (GTK_LABEL(respons5b), vetement1.accessoires);
							

					}
	} 
