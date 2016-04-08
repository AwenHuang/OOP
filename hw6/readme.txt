1.學號 : 400410048
2.姓名 : 黃韻文
3.email : 
4.開發環境: 系上工作站
5.操作說明 :
------------------------------------------------------
利用繼承使derived class可以使用base class的內容
用虛擬繼承讓derived class可以重新自行定義function內容

<makefile>
	使用者輸入 make 生成hw6執行檔
 	使用者輸入 make clear 清除hw6執行檔
<hw6.h>
	將各個class(Shape、Circle、Rectangle、Triangle)宣告在此檔，因此次作業並無特別要求要分三個檔案，故按照老師PDF內所述，也把各function內容打在此檔內

<main.cpp>
	利用vector的方式將資料一一儲存起來，宣告指標型態的物件，用new(有點像是C中的malloc)給他空間。
	因為作業要求color是string型態，故宣告string型態的陣列去存放各個顏色字串，放入各個形狀的資料之中。
	用for迴圈呼叫print()函式印出vector中的資料。
	利用dynamic_cast檢查型態來印Circle型態的資料。
	最後用for迴圈來逐一delete資料，用clear清除存在Shape中的color。
	
	
	
	
	
