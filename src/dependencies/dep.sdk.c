
#ifndef BearSSL_OPENAI_ONE
#define BearSSL_OPENAI_ONE
#ifndef SDK_OpenAI_dep
#define SDK_OpenAI_dep


#endif

#ifndef SDK_OpenAI_macros
#define SDK_OpenAI_macros
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



#define OPENAI_TYPE_IS_INVALID -1
#define OPENAI_TYPE_IS_NULL 0
#define OPENAI_TYPE_IS_OBJECT 1
#define OPENAI_TYPE_IS_ARRAY 2
#define OPENAI_TYPE_IS_STRING 3
#define OPENAI_TYPE_IS_NUMBER 4
#define OPENAI_TYPE_IS_BOOL 5




#endif

#ifndef SDK_OpenAI_types
#define SDK_OpenAI_types
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


typedef cJSON OpenAiResponse;


#endif

#ifndef SDK_OpenAI_typesA
#define SDK_OpenAI_typesA
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


typedef struct OpenAiArgument{
  const char *name_argument;
  const char *type;
  const char *description;
  bool required;
}OpenAiArgument;

typedef struct OpenAiCallback{
  char *(*Lambda)(cJSON *args, void *pointer);
  const char *description;
  long size_parameters;
  OpenAiArgument **parameters;
  const char *name_function;
  char *index_name;
  long index;
  bool check_heap;
  void *pointer;
}OpenAiCallback;







#endif

#ifndef SDK_OpenAI_typesB
#define SDK_OpenAI_typesB
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



struct OpenAiInterface{
    int max_retrys;
    #ifdef OPEN_AI_ALLOW_DTW

    char *cache_dir;
    bool cache_enabled;
    bool preserve_meta_info;
    #endif 
    BearHttpsRequest *request;
    cJSON *messages;

    int *temp_messages;
    int total_temp_menssages;
    int total_temp_messages_alocated;

    cJSON *body_object;
    cJSON *response_array;
    
    long size_callbakcs;
    OpenAiCallback **callbacks;
};
typedef struct OpenAiInterface OpenAiInterface;





#endif

#ifndef SDK_OpenAI_typesC
#define SDK_OpenAI_typesC
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


typedef struct OpenAiInterfaceNamespace {

    OpenAiInterface * (*newOpenAiInterface)(const char *url, const char *apiKey,const char *model);
    OpenAiResponse * (*get_response_by_index)(OpenAiInterface *self, long index);


    ///cache 
    #ifdef OPEN_AI_ALLOW_DTW
        void (*set_cache)(OpenAiInterface *self,const char *cache_dir,bool preserve_meta_info);
        void (*allow_cache)(OpenAiInterface *self);
        void (*disallow_cache)(OpenAiInterface *self);
    #endif 


    ///prompts
    void (*add_system_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_user_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_assistent_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_developer_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_tool_prompt)(OpenAiInterface *self, const char *id_call, const char *content);
    ///temp prompts
    void (*add_temp_system_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_temp_user_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_temp_assistent_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_temp_developer_prompt)(OpenAiInterface *self, const char *prompt);

    ///configs
    void (*set_know_ips)(OpenAiInterface *self, const char *url);
    void (*set_max_tokens)(OpenAiInterface *self, float max_tokens);
    void (*set_temperature)(OpenAiInterface *self, float temperature);
    void (*set_model)(OpenAiInterface *self, const char *model);
    void (*set_source_model)(OpenAiInterface *self, const char *source_model);

    //extras
    OpenAiResponse *  (*make_question)(OpenAiInterface *self);
    bool (*error)(OpenAiResponse *response);
    char *(*get_error_message)(OpenAiResponse *response);
    void  (*add_response_to_history)(OpenAiInterface *self, OpenAiResponse *response,int choice);

   
    void (*free)(OpenAiInterface *self);

} OpenAiInterfaceNamespace;

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

typedef struct OpenAiResponseNamespace{

    cJSON *(*get_choice)(OpenAiResponse *response, long choice);
    cJSON * (*get_message)(OpenAiResponse *response,long choice);
    cJSON  *(*get_content)(OpenAiResponse *response, long choice);
    const char * (*get_content_str)(OpenAiResponse *response,long choice);
    bool (*error)(OpenAiResponse *response);
    char *(*get_error_message)(OpenAiResponse *response);

}OpenAiResponseNamespace;
#endif

#ifndef SDK_OpenAI_typesD
#define SDK_OpenAI_typesD
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

typedef struct OpenAiNamespace{
    
    OpenAiResponseNamespace  response;
    OpenAiInterfaceNamespace openai_interface; 
}OpenAiNamespace;
#endif

#ifndef SDK_OpenAI_dec
#define SDK_OpenAI_dec
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


#ifdef OPEN_AI_ALLOW_DTW
void OpenAiInterface_set_cache(OpenAiInterface *self,const char *cache_dir,bool preserve_meta_info);

void OpenAiInterface_allow_cache(OpenAiInterface *self);

void OpenAiInterface_disallow_cache(OpenAiInterface *self);

cJSON *private_OpenAiInterface_get_cache_answer(OpenAiInterface *self);

void privateOpenAiInterface_save_answer_cache(OpenAiInterface *self, cJSON *response);
#endif 

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


int OpenAiInterface_add_callback_function_by_tools(
  OpenAiInterface *self,
  OpenAiCallback *callback
);

int OpenAiInterface_add_parameters_in_callback(
  OpenAiCallback *callback,
  const char *name_argument,
  const char *description,
  const char *type,
  bool required
);

char *OpenAiInterface_run_callback_by_index(OpenAiInterface *self, const char *name_function, const char *args);



//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end






void OpenAiInterface_set_know_ips(OpenAiInterface *self,const char *url);

void OpenAiInterface_set_max_tokens(OpenAiInterface *self, float temperature);

void OpenAiInterface_set_temperature(OpenAiInterface *bearOpenAi, float temperature);

void OpenAiInterface_set_model(OpenAiInterface *bearOpenAi, const char *model);


void OpenAiInterface_set_source_model(OpenAiInterface *bearOpenAi, const char *source_model);




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end




bool OpenAiResponse_error(OpenAiResponse *response);

char *OpenAiResponse_get_error_message(OpenAiResponse *response);

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



void OpenAiInterface_add_raw_prompt(OpenAiInterface *self, cJSON *prompt, bool permanent);

void OpenAiInterface_add_default_prompt(OpenAiInterface *self,const char *role, const char *prompt, bool permanent);

void OpenAiInterface_add_system_prompt(OpenAiInterface *self, const char *prompt);

void OpenAiInterface_add_user_prompt(OpenAiInterface *self, const char *prompt);

void OpenAiInterface_add_assistent_prompt(OpenAiInterface *self, const char *prompt);

void OpenAiInterface_add_developer_prompt(OpenAiInterface *self, const char *prompt);

void OpenAiInterface_add_tool_prompt(OpenAiInterface *self, const char *id_call, const char *content);

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end




OpenAiResponse *  OpenAiInterface_make_question(OpenAiInterface *self);

OpenAiResponse *OpenAiInterface_make_question_finish_reason_treated(OpenAiInterface *self);

void  OpenAiInterface_add_response_to_history(OpenAiInterface *self, OpenAiResponse *response,int choice);



void  OpenAiInterface_add_response_to_history(OpenAiInterface *self, OpenAiResponse *response,int choice);





//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


void privateOpenAiInterface_set_last_message_as_temp(OpenAiInterface *self);

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



void OpenAiInterface_add_temp_system_prompt(OpenAiInterface *self, const char *prompt);

void OpenAiInterface_add_temp_user_prompt(OpenAiInterface *self, const char *prompt);

void OpenAiInterface_add_temp_assistent_prompt(OpenAiInterface *self, const char *prompt);

void OpenAiInterface_add_temp_developer_prompt(OpenAiInterface *self, const char *prompt);


//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end






cJSON *private_OpenAiInterface_create_tool_object(
  OpenAiCallback *self,
  const char *type,
  bool additionalProperties,
  bool strict
);



//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



void OpenAiInterface_add_tools_raw(OpenAiInterface *self, cJSON *object);




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



long private_OpenAiExtra_extract_index(const char *input);




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end




OpenAiCallback *new_OpenAiCallback(
  char *(*Lambda)(cJSON *args, void *pointer),
  void *pointer,
  const char *name_func,
  const char *description,
  bool check_heap
);

void OpenAiCallback_free(OpenAiCallback *self);




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



OpenAiInterface * newOpenAiInterface(const char *url, const char *apiKey,const char *model);

void OpenAiInterface_free(OpenAiInterface *self);



//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



OpenAiArgument *private_new_OpenAiArgument(
  const char *name_argument,
  const char *description,
  const char *type,
  bool required
);

void private_OpenAiArgument_free(OpenAiArgument *self);




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

OpenAiInterfaceNamespace newOpenAiInterfaceNamespace();
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

OpenAiNamespace newOpenAiNamespace();
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

OpenAiResponseNamespace newOpenAiResponseNamespace();
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


OpenAiResponse * OpenAiInterface_get_response_by_index(OpenAiInterface *self, long index);

cJSON *OpenAiResponse_get_choice(OpenAiResponse *response, long choice);



//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end







cJSON * OpenAiResponse_get_message(OpenAiResponse *response,long choice);


cJSON  *OpenAiResponse_get_content(OpenAiResponse *response, long choice);


const char * OpenAiResponse_get_content_str(OpenAiResponse *response,long choice);




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end





cJSON *OpenAiResponse_get_tool_calls(OpenAiResponse *response, long choice, long *size_array);

cJSON *OpenAiResponse_get_object_tool_calls(OpenAiResponse *response, long choice, long index);

const char *OpenAiResponse_get_id_tool_calls_by_index(OpenAiResponse *response, long choice, long index);

const char *OpenAiResponse_get_value_item_in_obj_tool_calls_function(OpenAiResponse *response, long choice, long index, const char *item);

const char *OpenAiResponse_get_name_func_tool_calls_by_index(OpenAiResponse *response, long choice, long index);

const char *OpenAiResponse_get_arguments_func_tool_calls_by_index(OpenAiResponse *response, long choice, long index);





//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


const char *OpenAiResponse_get_finish_reason(OpenAiResponse *response, long choice);

bool OpenAiResponse_finish_reason_is_tool_calls(OpenAiResponse *response, long choice);




#endif

#ifndef SDK_OpenAI_def
#define SDK_OpenAI_def

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

#ifdef OPEN_AI_ALLOW_DTW

void OpenAiInterface_set_cache(OpenAiInterface *self,const char *cache_dir,bool preserve_meta_info){
    self->cache_dir = private_BearsslHttps_strdup(cache_dir);
    self->cache_enabled = true;
    self->preserve_meta_info = preserve_meta_info;
}

void OpenAiInterface_allow_cache(OpenAiInterface *self){
    self->cache_enabled = true;
}

void OpenAiInterface_disallow_cache(OpenAiInterface *self){
    self->cache_enabled = false;
}

void private_OpenAiInterface_digest_cache_entries(OpenAiInterface *self,char bufff[33]){
    DtwHash *hash = newDtwHash();
    char *messages_print = cJSON_Print(self->messages);
    DtwHash_digest_string(hash, messages_print);
    char *model = cJSON_GetObjectItem(self->body_object, "model")->valuestring;
    DtwHash_digest_string(hash, model);
    sprintf(bufff, "%s", hash->hash);
    free(messages_print);
    DtwHash_free(hash);

}

char *private_OpenAiIntereface_get_cache_answer_json_path(OpenAiInterface *self ,const char *entres_buff){
    char *path = (char*)malloc(
        strlen(self->cache_dir) +
        strlen(entres_buff) +
        sizeof("answer.json")+
        3
    );
    sprintf(path, "%s/%s/answer.json", self->cache_dir, entres_buff);
    return path;
}

cJSON *private_OpenAiInterface_get_cache_answer(OpenAiInterface *self){
    if(!self->cache_enabled){
        return NULL;
    }

    char hash[65] = {0};
    private_OpenAiInterface_digest_cache_entries(self, hash);
    char *path = private_OpenAiIntereface_get_cache_answer_json_path(self, hash);
    cJSON *response = NULL;
    if(dtw_entity_type(path) == DTW_FILE_TYPE){
        char *content = dtw_load_string_file_content(path);
        response = cJSON_Parse(content);
        free(content);
    }

    free(path);
    return response;
}


void privateOpenAiInterface_save_answer_cache(OpenAiInterface *self, cJSON *response){
    if(!self->cache_enabled){
        return;
    }
    char hash[65] = {0};
    private_OpenAiInterface_digest_cache_entries(self, hash);
    
    char *path = private_OpenAiIntereface_get_cache_answer_json_path(self, hash);
    char *content = cJSON_Print(response);
    dtw_write_string_file_content(path, content);
    
    if(self->preserve_meta_info){
        char *question_path = (char*)malloc(
            strlen(self->cache_dir) +
            sizeof(hash) +
            sizeof("question.json")+
            3
        );
        sprintf(question_path, "%s/%s/question.json", self->cache_dir, hash);
        char *question_content = cJSON_Print(self->body_object);
        dtw_write_string_file_content(question_path, question_content);
        free(question_content);
        free(question_path);
    }
    
    free(content);
    free(path);

    
}
#endif 

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



int OpenAiInterface_add_callback_function_by_tools(
  OpenAiInterface *self,
  OpenAiCallback *callback
){

  callback->index = self->size_callbakcs;
  
  cJSON *tool_object = private_OpenAiInterface_create_tool_object(
    callback,
    "function",
    false,
    true
  );

  if(!tool_object){
    OpenAiCallback_free(callback);
    return 0;
  }

  OpenAiCallback **now_struct = (OpenAiCallback **)BearsslHttps_reallocate(self->callbacks, sizeof(OpenAiCallback *) * (self->size_callbakcs + 1));
  if(!now_struct){
    OpenAiCallback_free(callback);
    return 0;
  }

  self->callbacks = now_struct;
  self->callbacks[self->size_callbakcs] = callback;
  self->size_callbakcs++;

  OpenAiInterface_add_tools_raw(self, tool_object);
  
  return 1;
}

int OpenAiInterface_add_parameters_in_callback(
  OpenAiCallback *callback,
  const char *name_argument,
  const char *description,
  const char *type,
  bool required
){
  
  OpenAiArgument *now_argument = private_new_OpenAiArgument(name_argument, description, type, required);

  OpenAiArgument **arguments = (OpenAiArgument **)BearsslHttps_reallocate(callback->parameters, sizeof(OpenAiArgument*) * (callback->size_parameters + 1));
  if(!arguments){
    private_OpenAiArgument_free(now_argument);
    return 0;
  }

  callback->parameters = arguments;
  callback->parameters[callback->size_parameters] = now_argument;
  callback->size_parameters++;

  return 1;
}

char *OpenAiInterface_run_callback_by_index(OpenAiInterface *self, const char *name_function, const char *args){
  
  long index_lambda = private_OpenAiExtra_extract_index(name_function);

  if(index_lambda >= self->size_callbakcs){
    return NULL;
  }

  OpenAiCallback *lambda = self->callbacks[index_lambda];

  if(!lambda){
    return NULL;
  }

  cJSON *arguments = cJSON_Parse(args);
  char *response = lambda->Lambda(arguments, lambda->pointer);
  cJSON_Delete(arguments);
  if(lambda->check_heap){
    BearsslHttps_free(response);
  }
  return response;
}




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



void OpenAiInterface_set_know_ips(OpenAiInterface *self,const char *url){
    if(strcmp(url,"https://api.openai.com/v1/chat/completions") == 0){
        static const char *open_ai_ips[] = {
            "172.66.0.243",
            "162.159.140.245"
        };
        BearHttpsRequest_set_known_ips(self->request, open_ai_ips, 2);
    }
}

void OpenAiInterface_set_temperature(OpenAiInterface *self, float temperature){
    cJSON_DeleteItemFromObjectCaseSensitive(self->body_object, "temperature");
    cJSON_AddNumberToObject(self->body_object, "temperature", temperature);
}

void OpenAiInterface_set_max_tokens(OpenAiInterface *self, float temperature){
    cJSON_DeleteItemFromObjectCaseSensitive(self->body_object, "max_tokens");
    cJSON_AddNumberToObject(self->body_object, "max_tokens", temperature);
}
void OpenAiInterface_set_model(OpenAiInterface *self, const char *model){
    cJSON_DeleteItemFromObjectCaseSensitive(self->body_object, "model");
    cJSON_AddStringToObject(self->body_object, "model", model);
}



void OpenAiInterface_set_source_model(OpenAiInterface *bearOpenAi, const char *source_model){
    cJSON_DeleteItemFromObjectCaseSensitive(bearOpenAi->body_object, "source_model");
    cJSON_AddStringToObject(bearOpenAi->body_object, "source_model", source_model);
}
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


bool OpenAiResponse_error(OpenAiResponse *response){
    if(response == NULL){
        return true;
    }
    cJSON *error = cJSON_GetObjectItem(response, "error");
    if(error == NULL){
        return false;
    }
    return true;
}

char *OpenAiResponse_get_error_message(OpenAiResponse *response){
    if(response == NULL){
        char *response_temp = (char *)"Response Invalid;";
        return response_temp;
    }
    cJSON *error = cJSON_GetObjectItem(response, "error");
    if(error == NULL){
        return NULL;
    }
    cJSON *message = cJSON_GetObjectItem(error, "message");
    if(message == NULL){
        return NULL;
    }
    return message->valuestring;
}




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



void OpenAiInterface_add_raw_prompt(OpenAiInterface *self, cJSON *prompt, bool permanent){

    cJSON_AddItemToArray(self->messages, prompt);
    
    if(!permanent){
        privateOpenAiInterface_set_last_message_as_temp(self);
    }

}

void OpenAiInterface_add_default_prompt(OpenAiInterface *self,const char *role, const char *prompt, bool permanent){
    cJSON *prompt_object = cJSON_CreateObject();

    cJSON_AddStringToObject(prompt_object, "role", role);
    cJSON_AddStringToObject(prompt_object, "content", prompt);
    cJSON_AddItemToArray(self->messages, prompt_object);
    if(!permanent){
        privateOpenAiInterface_set_last_message_as_temp(self);
    }
}

void OpenAiInterface_add_system_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "system", prompt, true);
}

void OpenAiInterface_add_user_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "user", prompt, true);
}

void OpenAiInterface_add_assistent_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "assistant", prompt, true);
}
void OpenAiInterface_add_developer_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "developer", prompt, true);
}

void OpenAiInterface_add_tool_prompt(OpenAiInterface *self, const char *id_call, const char *content){
    cJSON *prompt_tool = cJSON_CreateObject();
    cJSON_AddStringToObject(prompt_tool, "role", "tool");
    cJSON_AddStringToObject(prompt_tool, "tool_call_id", id_call);
    if(!content){
        cJSON_AddStringToObject(prompt_tool, "content", content);
    }else{
        cJSON_AddStringToObject(prompt_tool, "content", "");
    }
    OpenAiInterface_add_raw_prompt(self, prompt_tool, true);
}




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end




OpenAiResponse *OpenAiInterface_make_question(OpenAiInterface *self){
  

  #ifdef OPEN_AI_ALLOW_DTW
    cJSON *cached_json = private_OpenAiInterface_get_cache_answer(self);
    if(cached_json){        
          cJSON_AddItemToArray(self->response_array, cached_json);
          return cached_json;
    }

  #endif

  BearHttpsResponse *response = BearHttpsRequest_fetch(self->request);

  for(int i  = self->total_temp_menssages-1; i >= 0;i--){
    int index_to_destroy = self->temp_messages[i];
    cJSON_DeleteItemFromArray(self->messages, index_to_destroy);
  }


  self->total_temp_menssages = 0;

  const char * body = BearHttpsResponse_read_body_str(response);

  if(BearHttpsResponse_error(response)){
    char *error_msg = BearHttpsResponse_get_error_msg(response);
    cJSON *error_json = cJSON_CreateObject();
    cJSON *messsage =  cJSON_CreateString(error_msg);
    cJSON_AddItemToObject(error_json, "message", messsage);
    cJSON_AddItemToArray(self->response_array, error_json);
    BearHttpsResponse_free(response);
    return error_json; 
  }
  cJSON *json = cJSON_Parse(body);
  BearHttpsResponse_free(response);


  if(!json){
    cJSON *error_json = cJSON_CreateObject();
    cJSON *messsage =  cJSON_CreateString("Error parsing json");
    cJSON_AddItemToObject(error_json, "message", messsage);
    cJSON_AddItemToArray(self->response_array, error_json);
    return error_json;
  }

  cJSON_AddItemToArray(self->response_array, json);

  #ifdef OPEN_AI_ALLOW_DTW
    privateOpenAiInterface_save_answer_cache(self, json);    
  #endif
  
  return json;
}

OpenAiResponse *OpenAiInterface_make_question_finish_reason_treated(OpenAiInterface *self){

  int max_questions = 0;

  while(max_questions < 30){

    max_questions++;

    OpenAiResponse *response = OpenAiInterface_make_question(self);
    if(OpenAiResponse_error(response)){
      return NULL;
    }

    bool callbacks_finished = OpenAiResponse_finish_reason_is_tool_calls(response, 0);
    if(!callbacks_finished){
      return response;
    }

    OpenAiInterface_add_response_to_history(self, response, 0);
    
    long size_array = 0;
    cJSON *tool_calls = OpenAiResponse_get_tool_calls(response, 0, &size_array);

    for(int i=0; i < size_array; i++){
      const char *id = OpenAiResponse_get_id_tool_calls_by_index(response, 0, i);
      if(!id){
        return NULL;
      }
      const char *name = OpenAiResponse_get_name_func_tool_calls_by_index(response, 0, i);
      if(!name){
        return NULL;
      }
      const char *arguments = OpenAiResponse_get_arguments_func_tool_calls_by_index(response, 0, i);
      if(!arguments){
        return NULL;
      }

      const char *response_callback = OpenAiInterface_run_callback_by_index(self, name, arguments);

      OpenAiInterface_add_tool_prompt(self, id, response_callback);
    }
  }

  return NULL;
}


void  OpenAiInterface_add_response_to_history(OpenAiInterface *self, OpenAiResponse *response,int choice){   
  cJSON *message = OpenAiResponse_get_message(response,choice);
  cJSON *copy = cJSON_Duplicate(message,1);
  cJSON_AddItemToArray(self->messages, copy);
}


//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


void privateOpenAiInterface_set_last_message_as_temp(OpenAiInterface *self){
    int required_permanent_size = (self->total_temp_menssages +1) *sizeof(int);
    
    if(self->total_temp_messages_alocated <= required_permanent_size){
        self->total_temp_messages_alocated = required_permanent_size  *2; 
        self->temp_messages = (int*)realloc(self->temp_messages, self->total_temp_messages_alocated);
    }

    int last_index = cJSON_GetArraySize(self->messages) -1;
    self->temp_messages[self->total_temp_menssages] = last_index;
    self->total_temp_menssages++;
    
}
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


void OpenAiInterface_add_temp_system_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "system", prompt, false);
}

void OpenAiInterface_add_temp_user_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "user", prompt, false);
}

void OpenAiInterface_add_temp_assistent_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "assistant", prompt, false);
}

void OpenAiInterface_add_temp_developer_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "developer", prompt, true);
}




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


cJSON *private_OpenAiInterface_create_tool_object(
  OpenAiCallback *self,
  const char *type,
  bool additionalProperties,
  bool strict
){
  
  cJSON *tool_object = cJSON_CreateObject();
  cJSON_AddStringToObject(tool_object, "type", "function");

  cJSON *function = cJSON_AddObjectToObject(tool_object, "function");

  long sizing_index_name = snprintf(NULL, 0, "%ld_%s", self->index, self->name_function) + 1;
  self->index_name = (char *)BearsslHttps_allocate(sizing_index_name);
  if(!self->index_name){
    cJSON_Delete(tool_object);
    return NULL;
  }

  sprintf(self->index_name, "%ld_%s", self->index, self->name_function);
  cJSON_AddStringToObject(function, "name", self->index_name);
  cJSON_AddStringToObject(function, "description", self->description);
  cJSON_AddBoolToObject(function, "strict", strict);

  cJSON *parameters = cJSON_AddObjectToObject(function, "parameters");
  cJSON_AddStringToObject(parameters, "type", "object");
  cJSON_AddBoolToObject(parameters, "additionalProperties", additionalProperties);

  cJSON *required = cJSON_AddArrayToObject(parameters, "required");
  cJSON *properties = cJSON_AddObjectToObject(parameters, "properties");

  for(int i=0; i < self->size_parameters; i++){
    const char *name_value = self->parameters[i]->name_argument;
    
    cJSON *argument_obj = cJSON_AddObjectToObject(properties, name_value);
    cJSON_AddStringToObject(argument_obj, "type", self->parameters[i]->type);
    cJSON_AddStringToObject(argument_obj, "description", self->parameters[i]->description);

    if(self->parameters[i]->required){
      cJSON *name_argument = cJSON_CreateString(name_value);
      
      cJSON_AddItemToArray(required, name_argument);
    }

  }

  return tool_object;
}




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


void OpenAiInterface_add_tools_raw(OpenAiInterface *self, cJSON *object){
  cJSON *OpenAi_tools = cJSON_GetObjectItem(self->body_object, "tools");

  if(!OpenAi_tools){
    OpenAi_tools = cJSON_CreateArray();
    cJSON_AddItemToObject(self->body_object, "tools", OpenAi_tools);
  }

  cJSON_AddItemToArray(OpenAi_tools, object);
}







//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end




long private_OpenAiExtra_extract_index(const char *input) {
    const char *underscore_pos = strchr(input, '_');
    if (underscore_pos != NULL) {
        size_t length = underscore_pos - input;

        char substring[length + 1];
        strncpy(substring, input, length);
        substring[length] = '\0';

        return strtol(substring, NULL, 10);
    }
    return 0;
}




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end





OpenAiCallback *new_OpenAiCallback(
  char *(*Lambda)(cJSON *args, void *pointer),
  void *pointer,
  const char *name_func,
  const char *description,
  bool check_heap
){
  OpenAiCallback *self = (OpenAiCallback *)BearsslHttps_allocate(sizeof(OpenAiCallback));
  if(!self){
    printf("\n\tError:. allocate struct OpenAiCallback in error;\n");
    exit(1);
  }

  *self = (OpenAiCallback){0};

  self->Lambda = Lambda;
  self->name_function = name_func;
  self->index_name = NULL;
  self->description = description;

  self->size_parameters = 0;
  self->parameters = (OpenAiArgument **)BearsslHttps_allocate(sizeof(OpenAiArgument *));

  if(!self->parameters){
    BearsslHttps_free(self);
    return NULL;
  }
  
  *self->parameters = (OpenAiArgument*){0};

  self->check_heap = check_heap;
  self->pointer = pointer;
  
  return self;
}

void OpenAiCallback_free(OpenAiCallback *self){
  if(!self){
    return;
  }

  if(self->index_name){
    BearsslHttps_free(self->index_name);
  }
  
  if(self->parameters){
  
    for(int i=0; i < self->size_parameters; i++){
      private_OpenAiArgument_free(self->parameters[i]);
    }

    BearsslHttps_free(self->parameters);
  }

  BearsslHttps_free(self);
}








//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


OpenAiInterface *newOpenAiInterface(const char *url, const char *apiKey,const char *model){
  OpenAiInterface *self = (OpenAiInterface*)BearsslHttps_allocate(sizeof(OpenAiInterface));
  *self = (OpenAiInterface){0};
  self->request = newBearHttpsRequest(url);
  OpenAiInterface_set_know_ips(self, url);
  BearHttpsRequest_set_method(self->request, "POST");
  BearHttpsRequest_add_header_fmt(self->request, (char *)"Authorization", (char *)"Bearer %s", apiKey);
  //set cache to 0
  self->body_object = BearHttpsRequest_create_cJSONPayloadObject(self->request);
  self->messages = cJSON_CreateArray();
  OpenAiInterface_set_model(self, model);

  self->temp_messages = (int*)BearsslHttps_allocate(1);
  self->total_temp_messages_alocated = 1;

  cJSON_AddItemToObject(self->body_object, "messages", self->messages);
  self->response_array = cJSON_CreateArray();

  self->size_callbakcs = 0;
  self->callbacks = (OpenAiCallback **)BearsslHttps_allocate(sizeof(OpenAiCallback *));
  if(!self->callbacks){
    OpenAiInterface_free(self);
    return NULL;
  }
  *self->callbacks = (OpenAiCallback*){0};
  return self;
}

void OpenAiInterface_free(OpenAiInterface *self){
  #ifdef OPEN_AI_ALLOW_DTW
  if(self->cache_dir){
    free(self->cache_dir);
  }
  #endif
  if(self->callbacks){
    for(int i = 0; i < self->size_callbakcs; i++){
      OpenAiCallback_free(self->callbacks[i]);
    }
    BearsslHttps_free(self->callbacks);
  }
  if(self->temp_messages){
    BearsslHttps_free(self->temp_messages);
  }
  cJSON_Delete(self->response_array);
  BearHttpsRequest_free(self->request);
  BearsslHttps_free(self);
}



//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end






OpenAiArgument *private_new_OpenAiArgument(
  const char *name_argument,
  const char *description,
  const char *type,
  bool required
){
  OpenAiArgument *self = (OpenAiArgument *)BearsslHttps_allocate(sizeof(OpenAiArgument));
  if(!self){
    printf("\n\tErrro:. Allocate struct OpenAiArgument in error.\n");
    exit(1);
  }
  *self = (OpenAiArgument){0};

  self->name_argument = name_argument;
  self->description = description;
  self->type = type;
  self->required = required;

  return self;
}

void private_OpenAiArgument_free(OpenAiArgument *self){
  if(self){
    BearsslHttps_free(self);
  }
}




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

OpenAiInterfaceNamespace newOpenAiInterfaceNamespace(){
    OpenAiInterfaceNamespace self ={0};
    
    self.newOpenAiInterface = newOpenAiInterface;
    self.get_response_by_index = OpenAiInterface_get_response_by_index;

    #ifdef OPEN_AI_ALLOW_DTW
    self.set_cache = OpenAiInterface_set_cache;
    self.allow_cache = OpenAiInterface_allow_cache;
    self.disallow_cache = OpenAiInterface_disallow_cache;
    #endif

    self.add_system_prompt = OpenAiInterface_add_system_prompt;
    self.add_user_prompt = OpenAiInterface_add_user_prompt;
    self.add_assistent_prompt = OpenAiInterface_add_assistent_prompt;
    self.add_developer_prompt = OpenAiInterface_add_developer_prompt;
    self.add_tool_prompt = OpenAiInterface_add_tool_prompt;
    self.add_temp_system_prompt = OpenAiInterface_add_temp_system_prompt;
    self.add_temp_user_prompt = OpenAiInterface_add_temp_user_prompt;
    self.add_temp_assistent_prompt = OpenAiInterface_add_temp_assistent_prompt;
    self.add_temp_developer_prompt = OpenAiInterface_add_temp_developer_prompt;

    self.set_know_ips = OpenAiInterface_set_know_ips;
    self.set_max_tokens = OpenAiInterface_set_max_tokens;
    self.set_temperature = OpenAiInterface_set_temperature;
    self.set_model = OpenAiInterface_set_model;
    self.set_source_model = OpenAiInterface_set_source_model;

    self.add_response_to_history = OpenAiInterface_add_response_to_history;
    self.make_question = OpenAiInterface_make_question;
    self.error = OpenAiResponse_error;
    self.get_error_message = OpenAiResponse_get_error_message;

    self.free = OpenAiInterface_free;

    return self;
}
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


OpenAiNamespace newOpenAiNamespace(){
    OpenAiNamespace self ={0};
    self.openai_interface = newOpenAiInterfaceNamespace();
    self.response = newOpenAiResponseNamespace();
    return self;
}
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


OpenAiResponseNamespace newOpenAiResponseNamespace(){
    OpenAiResponseNamespace self ={0};
    self.get_choice = OpenAiResponse_get_choice;
    self.get_content = OpenAiResponse_get_content;
    self.get_content_str = OpenAiResponse_get_content_str;
    self.get_message = OpenAiResponse_get_message;
    self.error = OpenAiResponse_error;  
    self.get_error_message = OpenAiResponse_get_error_message;
    
    return self;
}
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

OpenAiResponse * OpenAiInterface_get_response_by_index(OpenAiInterface *self, long index){
  
    
    int size = cJSON_GetArraySize(self->response_array);
    //if index its -1 than its last
    if(index < 0){
        index = size + index;
    }
    if(index < 0 || index >= size){
        return NULL;
    }

    return cJSON_GetArrayItem(self->response_array, index);

}

cJSON *OpenAiResponse_get_choice(OpenAiResponse *response, long choice){
    if(response == NULL){
        return NULL;
    }
    cJSON *choices = cJSON_GetObjectItem(response, "choices");
    if(choices == NULL){
        return NULL;
    }
    return  cJSON_GetArrayItem(choices, choice);

}






//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


cJSON * OpenAiResponse_get_message(OpenAiResponse *response,long choice){
    cJSON *choice_item = OpenAiResponse_get_choice(response, choice);
    if(choice_item == NULL){
        return NULL;
    }
    cJSON *message = cJSON_GetObjectItem(choice_item, "message");
    if(message == NULL){
        return NULL;
    }
    return message;
}


cJSON *OpenAiResponse_get_content(OpenAiResponse *response, long choice){
    cJSON *message  =OpenAiResponse_get_message(response, choice);
    if(message == NULL){
        return NULL;
    }
    return cJSON_GetObjectItem(message, "content");
}


const char * OpenAiResponse_get_content_str(OpenAiResponse *response,long choice){
    cJSON *content = OpenAiResponse_get_content(response,choice);
    if(content == NULL){
        return NULL;
    }
    return content->valuestring;
}





//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



cJSON *OpenAiResponse_get_tool_calls(OpenAiResponse *response, long choice, long *size_array){
  
  cJSON *message = OpenAiResponse_get_message(response, choice);
  if(!message){
    return NULL;
  }

  cJSON *tool_calls = cJSON_GetObjectItemCaseSensitive(message, "tool_calls");

  if(size_array){
    if(!tool_calls){
      *size_array = 0;
    }
    if(tool_calls){
      *size_array = cJSON_GetArraySize(tool_calls);
    }
  }

  return tool_calls;
}

cJSON *OpenAiResponse_get_object_tool_calls(OpenAiResponse *response, long choice, long index){

  long max_size_array = 0;
  cJSON *tool_calls_array = OpenAiResponse_get_tool_calls(response, choice, &max_size_array);
  if(!tool_calls_array || index >= max_size_array){
    return NULL;
  }

  cJSON *obj_tool_calls = cJSON_GetArrayItem(tool_calls_array, index);

  return obj_tool_calls;  
}

const char *OpenAiResponse_get_id_tool_calls_by_index(OpenAiResponse *response, long choice, long index){
  cJSON *obj_tool_calls = OpenAiResponse_get_object_tool_calls(response, choice, index);
  if(!obj_tool_calls){
    return NULL;
  }

  cJSON *id = cJSON_GetObjectItemCaseSensitive(obj_tool_calls, "id");
  if(!id){
    return NULL;
  }

  return cJSON_GetStringValue(id);
}

const char *OpenAiResponse_get_value_item_in_obj_tool_calls_function(OpenAiResponse *response, long choice, long index, const char *item){
  cJSON *obj_tool_calls = OpenAiResponse_get_object_tool_calls(response, choice, index);
  if(!obj_tool_calls){
    return NULL;
  }

  cJSON *function = cJSON_GetObjectItemCaseSensitive(obj_tool_calls, "function");
  if(!function){
    return NULL;
  }

  cJSON *item_obj = cJSON_GetObjectItemCaseSensitive(function, item);
  if(!item_obj){
    return NULL;
  }

  return cJSON_GetStringValue(item_obj);
}

const char *OpenAiResponse_get_name_func_tool_calls_by_index(OpenAiResponse *response, long choice, long index){
  return OpenAiResponse_get_value_item_in_obj_tool_calls_function(response, choice, index, "name");
}

const char *OpenAiResponse_get_arguments_func_tool_calls_by_index(OpenAiResponse *response, long choice, long index){
  return OpenAiResponse_get_value_item_in_obj_tool_calls_function(response, choice, index, "arguments");
}






//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end




const char *OpenAiResponse_get_finish_reason(OpenAiResponse *response, long choice){

  cJSON *choice_obj = OpenAiResponse_get_choice(response, choice);
  if(!choice_obj){
    return NULL;
  }

  cJSON *finish_reason = cJSON_GetObjectItemCaseSensitive(choice_obj, "finish_reason");
  if(!finish_reason){
    return NULL;
  }

  return cJSON_GetStringValue(finish_reason);
}

bool OpenAiResponse_finish_reason_is_tool_calls(OpenAiResponse *response, long choice){

  const char *finished_reason = OpenAiResponse_get_finish_reason(response, choice);
  if(!finished_reason){
    return false;
  }

  if(strcmp("tool_calls", finished_reason) == 0){
    return true;
  }
  
  return false;
}




#endif

#endif

