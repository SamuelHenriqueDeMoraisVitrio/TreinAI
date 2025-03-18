/* This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
 */ 

#ifndef C_ARGV_PARSER_ONE
#define C_ARGV_PARSER_ONE
#ifndef CArgvParse_macros
#define CArgvParse_macros

#ifndef C_ARGV_PARSER_MAX_ARGS
#define C_ARGV_PARSER_MAX_ARGS 1000
#endif
#ifdef __cplusplus
#define C_ARGV_PARSER_NULL nullptr
#else
#define C_ARGV_PARSER_NULL ((void*)0)
#endif 


typedef unsigned char c_argv_bool;

#define C_ARGV_PARSER_TRUE 1
#define C_ARGV_PARSER_FALSE 0


#ifndef C_ARGV_UNUSED_START 
#define C_ARGV_UNUSED_START 1
#endif

#endif

#ifndef CArgvParse_types
#define CArgvParse_types
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


typedef struct CArgvParse{

    int used_args[C_ARGV_PARSER_MAX_ARGS];
    int total_used_args;
     char **args;
    int total_args;

    const char **flag_identifiers;
    int total_flag_indentifiers;

 }CArgvParse;

#endif

#ifndef CArgvParse_typesB
#define CArgvParse_typesB
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

typedef struct CArgvParseNamespace{

    CArgvParse (*newCArgvParse)(int argc, char **argv);

    const char *(*get_arg)(CArgvParse *self,int index);
    long long (*get_arg_number)(CArgvParse *self,int index);
    short (*get_arg_bool)(CArgvParse *self,int index);
    
    int (*get_flag_size)(CArgvParse *self,const char **flags,int flags_size);
    
    const char *(*get_flag)(CArgvParse *self ,const char **flags,int flags_size, int index);
    long long (*get_flag_number)(CArgvParse *self ,const char **flags,int flags_size, int index);
    short (*get_flag_bool)(CArgvParse *self ,const char **flags,int flags_size, int index);
    
    const char *(*get_next_unused_arg)(CArgvParse *self);
    long long (*get_next_unused_arg_number)(CArgvParse *self);
    short (*get_next_unused_arg_bool)(CArgvParse *self);
    
    c_argv_bool (*is_flags_present)(CArgvParse *self,const char **flag,int flags_size);
    
    c_argv_bool (*is_one_of_args_present)(CArgvParse *self,const char **args,int args_size);
    
    int (*get_infinity_flag_size)(CArgvParse *self,const char **flags,int flags_size);
    
    const char *(*get_infinty_flag)(CArgvParse *self ,const char **flags,int flags_size, int index);
    long long(*get_infinty_flag_number)(CArgvParse *self ,const char **flags,int flags_size, int index);
    short (*get_infinty_flag_bool)(CArgvParse *self ,const char **flags,int flags_size, int index);
    
    int (*get_compact_flag_size)(CArgvParse *self,const char **flags,int flags_size);
    
    const char * (*get_compact_flag)(CArgvParse *self ,const char **flags,int flags_size, int index);
    long long(*get_compact_flag_number)(CArgvParse *self ,const char **flags,int flags_size, int index);
    short (*get_compact_flag_bool)(CArgvParse *self ,const char **flags,int flags_size, int index);
    
}CArgvParseNamespace;

#endif

#ifndef CArgvParse_fdeclare
#define CArgvParse_fdeclare
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end





CArgvParse newCArgvParse(int argc, char **argv);

const char *CArgvParse_get_arg(CArgvParse *self,int index);

long long CArgvParse_get_arg_number(CArgvParse *self, int index);

short CArgvParse_get_arg_bool(CArgvParse *self, int index);

int privateCArgv_parser_get_flag_identifier_start_size(CArgvParse *self,const char *flag,int flag_size);

c_argv_bool CArgvParse_is_flags_present(CArgvParse *self,const char **flags,int flags_size);

c_argv_bool CArgvParse_is_one_of_args_present(CArgvParse *self,const char **args,int args_size);

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end






int CArgvParse_get_compact_flag_size(CArgvParse *self,const char **flags,int flags_size);

const char * CArgvParse_get_compact_flag(CArgvParse *self ,const char **flags,int flags_size, int index);

long long CArgvParse_get_compact_flag_number(CArgvParse *self ,const char **flags,int flags_size, int index);

short CArgvParse_get_compact_flag_bool(CArgvParse *self ,const char **flags,int flags_size, int index);

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


int CArgvParse_get_infinity_flag_size(CArgvParse *self,const char **flags,int flags_size);

const char * CArgvParse_get_infinty_flag(CArgvParse *self ,const char **flags,int flags_size, int index);

long long CArgvParse_get_infinty_flag_number(CArgvParse *self ,const char **flags,int flags_size, int index);

short CArgvParse_get_infinty_flag_bool(CArgvParse *self ,const char **flags,int flags_size, int index);

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

CArgvParseNamespace newCArgvParseNamespace();
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end






int CArgvParse_get_flag_size(CArgvParse *self,const char **flags,int flags_size);

const char * CArgvParse_get_flag(CArgvParse *self ,const char **flags,int flags_size, int index);

long long CArgvParse_get_flag_number(CArgvParse *self, const char **flags, int flags_size, int index);

short CArgvParse_get_flag_bool(CArgvParse *self ,const char **flags,int flags_size, int index);

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


c_argv_bool private_CArgvParse_its_used(CArgvParse *self,int index);

void private_CArgvParse_add_used(CArgvParse *self,int index);

const char *CArgvParse_get_next_unused_arg(CArgvParse *self);

long long CArgvParse_get_next_unused_arg_number(CArgvParse *self);

short CArgvParse_get_next_unused_arg_bool(CArgvParse *self);

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


short privateArgv_parser_string_cmp(const char *s1, const char *s2);

long long privateArgv_parser_string_to_long_long(const char *text);

long long privateArgv_parser_string_to_long_long_by_size(const char *text, long size_length);

int privateArgv_parser_string_size(const char *string);

c_argv_bool privateArgv_parsser_starts_with(const char *string,int string_size, const char *start,int start_size);

c_argv_bool privateArgv_strings_equals(const char *string1,int string1_size,const char *string2,int string2_size);


#endif

#ifndef CArgvParse_globals
#define CArgvParse_globals
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


const char *CArgvPars_defult_identifiers[] = {"--","-"};
const int CArgvPars_defult_identifiers_size = 2;
#endif

#ifndef CArgvParse_fdefine
#define CArgvParse_fdefine
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end






CArgvParse newCArgvParse(int argc, char **argv){
    CArgvParse cArgvPars ={0};
    cArgvPars.args = argv;
    cArgvPars.total_args = argc;
    cArgvPars.flag_identifiers = CArgvPars_defult_identifiers;
    cArgvPars.total_flag_indentifiers = CArgvPars_defult_identifiers_size;
    return cArgvPars;
}

const char *CArgvParse_get_arg(CArgvParse *self,int index){
    if(index < self->total_args){
        private_CArgvParse_add_used(self,index);
        return self->args[index];
    }
    return C_ARGV_PARSER_NULL;
}

long long CArgvParse_get_arg_number(CArgvParse *self, int index){
    return privateArgv_parser_string_to_long_long(CArgvParse_get_arg(self, index));
}

short CArgvParse_get_arg_bool(CArgvParse *self, int index){
    const char *response = CArgvParse_get_arg(self, index);
    short true_bool = privateArgv_parser_string_cmp(response, "true");
    short True_bool = privateArgv_parser_string_cmp(response, "True");
    short TRUE_bool = privateArgv_parser_string_cmp(response, "TRUE");

    if(true_bool || True_bool || TRUE_bool){
        return 1;
    }

    return 0;
}

c_argv_bool CArgvParse_is_flags_present(CArgvParse *self,const char **flags,int flags_size){
    
    for(int i = 0; i < self->total_args; i++){
        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        int identifier_start_size = privateCArgv_parser_get_flag_identifier_start_size(self,current_arg,current_arg_size);        
        c_argv_bool its_flag = identifier_start_size != -1;

        //means its not a flag
        if(!its_flag){
            continue;
        }
        const char *formmated_flag_comparaton_flag = current_arg + identifier_start_size;
        int formmated_flag_comparaton_flag_size = current_arg_size-identifier_start_size;

        for(int j = 0; j < flags_size;j++){
            const char *flag = flags[j];
            int flag_size = privateArgv_parser_string_size(flag);

            c_argv_bool is_the_current_flag = privateArgv_strings_equals(
                formmated_flag_comparaton_flag,
                formmated_flag_comparaton_flag_size,
                flag,
                flag_size
            );
            if(is_the_current_flag){
                private_CArgvParse_add_used(self,i);
                return C_ARGV_PARSER_TRUE;
            }
        }

    }
    return C_ARGV_PARSER_FALSE;
}





int privateCArgv_parser_get_flag_identifier_start_size(CArgvParse *self,const char *flag,int flag_size){
    for(int i = 0; i < self->total_flag_indentifiers; i++){
        const char *current_identifier = self->flag_identifiers[i];
        int current_identifier_size = privateArgv_parser_string_size(current_identifier);
        if(privateArgv_parsser_starts_with(flag,flag_size,current_identifier,current_identifier_size)){
            return current_identifier_size;
        }
    }
    return -1;
}
c_argv_bool CArgvParse_is_one_of_args_present(CArgvParse *self,const char **args,int args_size){
    for(int i = 0; i < self->total_args; i++){
        const char *current_arg = self->args[i];

        
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        for(int j = 0; j < args_size;j++){
            const char *arg = args[j];
            int arg_size = privateArgv_parser_string_size(arg);
            c_argv_bool is_the_current_arg = privateArgv_strings_equals(
                current_arg,
                current_arg_size,
                arg,
                arg_size
            );
            if(is_the_current_arg){
                private_CArgvParse_add_used(self,i);
                return C_ARGV_PARSER_TRUE;
            }
        }
    }
    return C_ARGV_PARSER_FALSE;
}

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end




int CArgvParse_get_compact_flag_size(CArgvParse *self,const char **flags,int flags_size){
    int size = 0;
    for(int i = 0; i < self->total_args; i++){
        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        for(int j=0; j < flags_size;j++){
            const char *flag = flags[j];
            int flag_size = privateArgv_parser_string_size(flag);
        
            if(privateArgv_parsser_starts_with(current_arg,current_arg_size,flag,flag_size)){
                size++;
            }
        }
    }
    return size;
}    


const char * CArgvParse_get_compact_flag(CArgvParse *self ,const char **flags,int flags_size, int index){
    int found=0;
    for(int i = 0; i < self->total_args; i++){

        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        for(int j=0; j < flags_size;j++){
            const char *flag = flags[j];
            int flag_size = privateArgv_parser_string_size(flag);
        
            if(privateArgv_parsser_starts_with(current_arg,current_arg_size,flag,flag_size)){
                if(found == index){
                    return current_arg + flag_size;
                }
                found++;
            }
        }
    }
    return C_ARGV_PARSER_NULL;
}

long long CArgvParse_get_compact_flag_number(CArgvParse *self ,const char **flags,int flags_size, int index){
    return privateArgv_parser_string_to_long_long(CArgvParse_get_compact_flag(self, flags, flags_size, index));
}

short CArgvParse_get_compact_flag_bool(CArgvParse *self ,const char **flags,int flags_size, int index){
    const char *response = CArgvParse_get_compact_flag(self ,flags, flags_size, index);
    short true_bool = privateArgv_parser_string_cmp(response, "true");
    short True_bool = privateArgv_parser_string_cmp(response, "True");
    short TRUE_bool = privateArgv_parser_string_cmp(response, "TRUE");

    if(true_bool || True_bool || TRUE_bool){
        return 1;
    }

    return 0;
}

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


int CArgvParse_get_infinity_flag_size(CArgvParse *self,const char **flags,int flags_size){
    int found=0;
    int flag_found_index = -1;
    c_argv_bool inside_flag = C_ARGV_PARSER_FALSE;
    for(int i = 0; i < self->total_args; i++){

        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        int identifier_start_size = privateCArgv_parser_get_flag_identifier_start_size(self,current_arg,current_arg_size);        
        c_argv_bool its_flag = identifier_start_size != -1;
        //means its not a flag
        if(!its_flag &&!inside_flag){
            continue;
        }

        if(!its_flag &&inside_flag){            
            found++;
            continue;
        }

        // if its here, than its a flag

        const char *formmated_flag_comparaton_flag = current_arg + identifier_start_size;
        int formmated_flag_comparaton_flag_size = current_arg_size-identifier_start_size;

        for(int j = 0; j < flags_size;j++){
            const char *flag = flags[j];
            int flag_size = privateArgv_parser_string_size(flag);

            c_argv_bool is_the_current_flag = privateArgv_strings_equals(
                formmated_flag_comparaton_flag,
                formmated_flag_comparaton_flag_size,
                flag,
                flag_size
            );
            if(is_the_current_flag){
                flag_found_index = i;
                inside_flag = C_ARGV_PARSER_TRUE;
                break;
            }
            if(!is_the_current_flag){
                inside_flag = C_ARGV_PARSER_FALSE;
                flag_found_index = -1;
            }
        }

    }
    return found;
}    


const char * CArgvParse_get_infinty_flag(CArgvParse *self ,const char **flags,int flags_size, int index){
    int found=0;
    int flag_found_index = -1;
    c_argv_bool inside_flag = C_ARGV_PARSER_FALSE;
    for(int i = 0; i < self->total_args; i++){

        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        int identifier_start_size = privateCArgv_parser_get_flag_identifier_start_size(self,current_arg,current_arg_size);        
        c_argv_bool its_flag = identifier_start_size != -1;
        //means its not a flag
        if(!its_flag &&!inside_flag){
            continue;
        }

        if(!its_flag &&inside_flag){            
            if(found == index){
                private_CArgvParse_add_used(self,flag_found_index);
                private_CArgvParse_add_used(self,i);
                return self->args[i];
            }        
            found++;
            continue;
        }

        // if its here, than its a flag

        const char *formmated_flag_comparaton_flag = current_arg + identifier_start_size;
        int formmated_flag_comparaton_flag_size = current_arg_size-identifier_start_size;

        for(int j = 0; j < flags_size;j++){
            const char *flag = flags[j];
            int flag_size = privateArgv_parser_string_size(flag);

            c_argv_bool is_the_current_flag = privateArgv_strings_equals(
                formmated_flag_comparaton_flag,
                formmated_flag_comparaton_flag_size,
                flag,
                flag_size
            );
            if(is_the_current_flag){
                flag_found_index = i;
                inside_flag = C_ARGV_PARSER_TRUE;
                break;
            }
            if(!is_the_current_flag){
                inside_flag = C_ARGV_PARSER_FALSE;
                flag_found_index = -1;
            }
        }

    }
    return C_ARGV_PARSER_NULL;
}

long long CArgvParse_get_infinty_flag_number(CArgvParse *self ,const char **flags,int flags_size, int index){
    return privateArgv_parser_string_to_long_long(CArgvParse_get_infinty_flag(self ,flags, flags_size, index));
}

short CArgvParse_get_infinty_flag_bool(CArgvParse *self ,const char **flags,int flags_size, int index){
    const char *response = CArgvParse_get_infinty_flag(self ,flags, flags_size, index);
    short true_bool = privateArgv_parser_string_cmp(response, "true");
    short True_bool = privateArgv_parser_string_cmp(response, "True");
    short TRUE_bool = privateArgv_parser_string_cmp(response, "TRUE");

    if(true_bool || True_bool || TRUE_bool){
        return 1;
    }

    return 0;
}


//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


CArgvParseNamespace newCArgvParseNamespace(){
  CArgvParseNamespace self ={0};
  self.newCArgvParse = newCArgvParse;
  
  self.get_arg = CArgvParse_get_arg;
  self.get_arg_number = CArgvParse_get_arg_number;
  self.get_arg_bool = CArgvParse_get_arg_bool;

  self.get_flag_size = CArgvParse_get_flag_size;
  
  self.get_flag = CArgvParse_get_flag;
  self.get_flag_number = CArgvParse_get_flag_number;
  self.get_flag_bool = CArgvParse_get_flag_bool;
  
  self.get_next_unused_arg = CArgvParse_get_next_unused_arg;
  self.get_next_unused_arg_number = CArgvParse_get_next_unused_arg_number;
  self.get_next_unused_arg_bool = CArgvParse_get_next_unused_arg_bool;
  
  self.is_flags_present = CArgvParse_is_flags_present;
  self.is_one_of_args_present = CArgvParse_is_one_of_args_present;
  self.get_infinity_flag_size = CArgvParse_get_infinity_flag_size;
  
  self.get_infinty_flag = CArgvParse_get_infinty_flag;
  self.get_infinty_flag_number = CArgvParse_get_infinty_flag_number;
  self.get_infinty_flag_bool = CArgvParse_get_infinty_flag_bool;
  
  self.get_compact_flag_size = CArgvParse_get_compact_flag_size;
  
  self.get_compact_flag = CArgvParse_get_compact_flag;
  self.get_compact_flag_number = CArgvParse_get_compact_flag_number;
  self.get_compact_flag_bool = CArgvParse_get_compact_flag_bool;
  
  return self;   
}

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end




int CArgvParse_get_flag_size(CArgvParse *self,const char **flags,int flags_size){
    int found=0;
    for(int i = 0; i < self->total_args-1; i++){


        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        int identifier_start_size = privateCArgv_parser_get_flag_identifier_start_size(self,current_arg,current_arg_size);        
        c_argv_bool its_flag = identifier_start_size != -1;
        //means its not a flag
        if(!its_flag){
            continue;
        }
        const char *formmated_flag_comparaton_flag = current_arg + identifier_start_size;
        int formmated_flag_comparaton_flag_size = current_arg_size-identifier_start_size;

        for(int j = 0; j < flags_size;j++){
            const char *flag = flags[j];
            int flag_size = privateArgv_parser_string_size(flag);

            c_argv_bool is_the_current_flag = privateArgv_strings_equals(
                formmated_flag_comparaton_flag,
                formmated_flag_comparaton_flag_size,
                flag,
                flag_size
            );
            if(is_the_current_flag){
                found++;
                break;
            }
        }

    }
    return found;
}    


const char * CArgvParse_get_flag(CArgvParse *self ,const char **flags,int flags_size, int index){
    int found=0;
    for(int i = 0; i < self->total_args-1; i++){


        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        int identifier_start_size = privateCArgv_parser_get_flag_identifier_start_size(self,current_arg,current_arg_size);        
        c_argv_bool its_flag = identifier_start_size != -1;
        //means its not a flag
        if(!its_flag){
            continue;
        }
        const char *formmated_flag_comparaton_flag = current_arg + identifier_start_size;
        int formmated_flag_comparaton_flag_size = current_arg_size-identifier_start_size;

        for(int j = 0; j < flags_size;j++){
            const char *flag = flags[j];
            int flag_size = privateArgv_parser_string_size(flag);

            c_argv_bool is_the_current_flag = privateArgv_strings_equals(
                formmated_flag_comparaton_flag,
                formmated_flag_comparaton_flag_size,
                flag,
                flag_size
            );
            if(is_the_current_flag){

                if(found == index){

                    private_CArgvParse_add_used(self,i);
                    private_CArgvParse_add_used(self,i+1);
                    const  char *next = self->args[i+1];
                    return next;
                }
                found++;
                break;
            }
        }

    }
    return C_ARGV_PARSER_NULL;
}

long long CArgvParse_get_flag_number(CArgvParse *self, const char **flags, int flags_size, int index){
    return privateArgv_parser_string_to_long_long(CArgvParse_get_flag(self, flags, flags_size, index));
}

short CArgvParse_get_flag_bool(CArgvParse *self ,const char **flags,int flags_size, int index){
    const char *response = CArgvParse_get_flag(self ,flags, flags_size, index);
    short true_bool = privateArgv_parser_string_cmp(response, "true");
    short True_bool = privateArgv_parser_string_cmp(response, "True");
    short TRUE_bool = privateArgv_parser_string_cmp(response, "TRUE");

    if(true_bool || True_bool || TRUE_bool){
        return 1;
    }

    return 0;
}


//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


c_argv_bool private_CArgvParse_its_used(CArgvParse *self,int index){
    for(int i = 0; i < self->total_used_args; i++){
        if(self->used_args[i] == index){
            return C_ARGV_PARSER_TRUE;
        }
    }
    return C_ARGV_PARSER_FALSE;
}
void private_CArgvParse_add_used(CArgvParse *self,int index){
    if(private_CArgvParse_its_used(self,index)){
        return;
    }
    if(self->total_used_args >= C_ARGV_PARSER_MAX_ARGS){
        return;
    }
    self->used_args[self->total_used_args] = index;
    self->total_used_args++;
}


const char *CArgvParse_get_next_unused_arg(CArgvParse *self){
    for(int i = C_ARGV_UNUSED_START; i < self->total_args; i++){
        if(!private_CArgvParse_its_used(self,i)){
            private_CArgvParse_add_used(self,i);
            return self->args[i];
        }
    }
    return C_ARGV_PARSER_NULL;
}

long long CArgvParse_get_next_unused_arg_number(CArgvParse *self){
    return privateArgv_parser_string_to_long_long(CArgvParse_get_next_unused_arg(self));
}

short CArgvParse_get_next_unused_arg_bool(CArgvParse *self){
    const char *response = CArgvParse_get_next_unused_arg(self);
    short true_bool = privateArgv_parser_string_cmp(response, "true");
    short True_bool = privateArgv_parser_string_cmp(response, "True");
    short TRUE_bool = privateArgv_parser_string_cmp(response, "TRUE");

    if(true_bool || True_bool || TRUE_bool){
        return 1;
    }

    return 0;
}

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


short privateArgv_parser_string_cmp(const char *s1, const char *s2) {
    if (!s1 || !s2){
        return 0;
    }

    while (*s1 && *s2) {
        if (*s1 != *s2){
            return 0;
        }
        s1++;
        s2++;
    }

    return (*s1 == *s2) ? 1 : 0;
}

long long privateArgv_parser_string_to_long_long(const char *text){
    if(!text){
        return 0;
    }

    int result = 0, sign = 1;

    if (*text == '-'){// Não vou colocar o + porque não faz sentido
        if (*text == '-') sign = -1;
        text++;
    }

    while (*text >= '0' && *text <= '9') {
        result = result * 10 + (*text - '0');//preciso fazer uma subtração pois é um valor ascii
        text++;
    }

    return result * sign;
}

long long privateArgv_parser_string_to_long_long_by_size(const char *text, long size_length){
    if(!text){
        return 0;
    }
    if(size_length <= 0){
        return 0;
    }
    if(privateArgv_parser_string_size(text) < size_length){
        return 0;
    }

    long long result = 0;
    int sign = 1;

    if (text[0] == '-'){
        sign = -1;
        if(size_length == 1){
            return 0;
        }
    }

    for(long i=1; i < size_length; i++){
        if(text[i] >= '0' || text[i] <= '9'){
            result = result * 10 + (text[i] - '0');
        }
        return 0;
    }

    return result * sign;
}

int privateArgv_parser_string_size(const char *string){
    int size = 0;
    while(string[size] != '\0'){
        size++;
    }
    return size;
}


c_argv_bool privateArgv_parsser_starts_with(const char *string,int string_size, const char *start,int start_size){    
    if(string_size < start_size){
        return 0;
    }
    for(int i = 0; i < start_size; i++){
        if(string[i] != start[i]){
            return 0;
        }
    }
    return 1;
}

c_argv_bool privateArgv_strings_equals(const char *string1,int string1_size,const char *string2,int string2_size){
    if(string1_size != string2_size){
        return 0;
    }
    for(int i = 0; i < string1_size; i++){
        if(string1[i] != string2[i]){
            return 0;
        }
    }
    return 1;
}

#endif

#endif 