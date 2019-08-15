#pragma once
#include "pch.h"
typedef int STATEMENT;
#define STATEMENT_FAIL 0;
#define STATEMENT_SUCCESS 1;
class stct_comment_info;

vector<stct_comment_info> infos;


class stct_comment_info {
public:
	string file_path;
	string line_index;
	string comment_text;
	string other;
	bool is_fail;
	~stct_comment_info() {}
	stct_comment_info(string file_pathT
		, string line_indexT
		, string comment_textT
		, string otherT = "") 
	{
		if (comment_text.size() > 500) is_fail = true;
		else
		{
			is_fail = false;
			file_path = file_pathT;
			line_index = line_indexT;
			comment_text = comment_textT;
			other = otherT;
		}
	}
	static STATEMENT add(stct_comment_info* ptr )
	{
		if (ptr->is_fail) return STATEMENT_FAIL;
		  
		infos.push_back(*ptr);
		delete ptr;
		return STATEMENT_SUCCESS;
	}

};


typedef void(*CALLBACK_FUN)(string);
void file_visit(string folder_path, CALLBACK_FUN deal_fun) {

	//遍历所有文件（.h and .cpp）
	deal_fun(folder_path);
}


string readline() {

}

void callback_visit(string file_path) {

	//打开文件

	
	string line;

	//定义上下文标志变量

	//遍历行
	while (!(line = readline()).empty()) {
	 
		//查找嫌疑注释行

		//检验嫌疑注释行

		//处理注释行

	}
	


}


