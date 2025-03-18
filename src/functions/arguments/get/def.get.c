//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end





const char *TreinAi_get_string_value_or_default(CArgvParse *args, const char *keys[], const char *value_default){
  const char *value = CArgvParse_get_flag(args, keys, 3, 0);
  return value?value:value_default;
}

long long TreinAi_get_number_type_value_or_default(CArgvParse *args, const char **keys, size_t value_default){
  long long value = CArgvParse_get_flag_number(args, keys, 3, 0);
  return value<=0?value_default:value;
}

TreinAi_Arguments *new_TreinAI_Arguments(CArgvParse *args){

  TreinAi_Arguments *self = BearsslHttps_allocate(sizeof(TreinAi_Arguments));
  if(!self){
    return NULL;
  }

  *self = (TreinAi_Arguments){0};

  self->size_buffer_max_in_KB = TreinAi_get_number_type_value_or_default(args, (const char *[]){"SB", "Sbuffer", "size_buffer"}, TREINAI_BUFFER_SIZE);
  self->url_api = TreinAi_get_string_value_or_default(args, (const char *[]){"URL", "Url", "url"}, TREINAI_CONFIG_URL_OPENAI);
  self->model_name = TreinAi_get_string_value_or_default(args, (const char *[]){"MODEL", "Model", "model"}, TREINAI_CONFIG_MODEL_DEFAULT);
  self->not_permision_write = CArgvParse_get_flag_bool(args, (const char *[]){"NW", "Nwrite", "not_write"}, 3, 1);
  self->path_history = TreinAi_get_string_value_or_default(args, (const char *[]){"PH", "Phistory", "path_history"}, NULL);
  self->path_get_key = TreinAi_get_string_value_or_default(args, (const char *[]){"PK", "Pkey", "path_key"}, NULL);

  self->key = TreinAi_get_string_value_or_default(args, (const char *[]){"KEY", "Key", "key"}, NULL);
  if(!self->key){
    printf("\n\tKEY not provieded.");
  }

  if(!self->key){
    BearsslHttps_free(self);
    return NULL;
  }

  return self;
}



