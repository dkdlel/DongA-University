%{
	#include <stdio.h>
	#include <string.h>
	typedef struct node_inf {
		char 	kind[10];
		union {
			double dv;
			char * sv;
		}		value;
		struct node_inf * 	bro;
		struct node_inf * 	son;
	} Node;

	Node *rootNode;
	int p;

	Node* createNode(char * kind, Node* bro, Node* son);
	void traverse(Node * nodeP); 
%}
%union {
	double dval;
	char * sval;
	struct node_inf * nodeP;
}
%token <dval> TNUMBER
%token <sval> TWORD
%token TPROGRAM TMAIN TPROC TFUNC TRETURNS TCALL TRETURN TBEGIN TEND TVAR TLONG TINT TAND TOR TNOT TLT TGT TLE TGE TNE TPLUS TMINUS TDIV TMUL TASS TWHILE TFOR TTO TIF TTHEN TELSE
%type <nodeP> Program VarDecl DclList Decl VarList Type Var SubPgmList SubPgm ProcDecl FuncDecl FormParam Stmt AsgnStmt IfStmt WhileStmt ForStmt CallStmt RtnStmt CompStmt StmtList Cond Rel Expr Term Fact FuncCall ParamList ExprList Name Number Goal

%% 
Goal		: Program { rootNode = $1; }	
Program 		: TPROGRAM Name ';' SubPgmList TMAIN VarDecl CompStmt '.'  { $$ = createNode("MAIN", $4, $6); $6->bro = $7; }	
		;
VarDecl	 	: TVAR DclList ';'   { $$ = createNode("VARDECL",NULL,$2); }
		| DclList { $$ = createNode("VARDECL",NULL,$1); }
		|  { $$ = createNode("VARDECL",NULL,NULL); }	
		;
CompStmt 	: TBEGIN StmtList TEND { $$ = createNode("COMP", NULL, $2); }				
		;
StmtList 		: Stmt ';' StmtList { $$ = $1; $1->bro = $3; }	
		| Stmt  { $$ = $1; }				
		;
DclList 		: Decl ',' DclList { $$ = createNode("DECL",$3, $1); }						
		| Decl { $$ = createNode("DECL",NULL,$1); }				
		; 
Decl 		: VarList ':' Type  { 	$$ = $1; while($1->bro != NULL){ $1=$1->bro; } $1->bro = $3; }				
		;	
VarList 		: Var ',' VarList { $$ = $1; $1->bro = $3; }				
		| Var { $$ = $1; }					
		;
Var 		: Name { $$ = $1; }							
		;
Type 		: TINT  { $$ = createNode("INT",NULL,NULL); }				
		| TLONG  { $$ = createNode("LONG",NULL,NULL); }						
		;
SubPgmList 	: SubPgm SubPgmList { $$ = createNode("SUBPGM", NULL, $1); $1->bro = $2; }						
		| { $$ = NULL; }					
		;
SubPgm 		: ProcDecl  { $$ = $1; }							
		| FuncDecl { $$ = $1; }							
		;
ProcDecl 		: TPROC Name '(' FormParam ')' VarDecl CompStmt  { $$ = createNode("PROC", NULL, $2); $2->bro=$4; $4->bro=$6; $6->bro=$7; } 			
		; 
FuncDecl 	: TFUNC Name '(' FormParam ')' TRETURNS '(' Type ')' VarDecl CompStmt  { $$ = createNode("FUNC", NULL, $2); $2->bro=$8; $8->bro=$4; $4->bro=$10; $10->bro=$11; }
		;
FormParam 	: VarDecl { $$ = $1; }
		;
Stmt		: AsgnStmt	{ $$ = $1; }						
		| IfStmt		{ $$ = $1; }								
		| WhileStmt	{ $$ = $1; }						
		| ForStmt		{ $$ = $1; }					
		| CallStmt	{ $$ = $1; }								
		| RtnStmt		{ $$ = $1; }								
		| CompStmt 	{ $$ = $1; }						
		;
AsgnStmt 	: Var TASS Expr { $$ = createNode("ASSIGN", NULL, $1);  $1->bro = $3; } 					
		; 
IfStmt 		: TIF '(' Cond ')' TTHEN Stmt TELSE Stmt { $$ = createNode("IF", NULL, $3); $3->bro=$6; $6->bro = $8; } 
		| TIF '(' Cond ')' TTHEN Stmt	{ $$ = createNode("IF", NULL, $3); $3->bro=$6; } 		
		;
WhileStmt 	: TWHILE '(' Cond ')' Stmt { $$ = createNode("WHILE", NULL, $3); $3->bro=$5; } 
		;	
ForStmt 		: TFOR '(' AsgnStmt TTO Expr ')' Stmt { $$ = createNode("FOR", NULL, $3); $3->bro=$5; $5->bro=$7; } 
		;
CallStmt 		: TCALL Name '(' ParamList ')' { $$ = createNode("PCALL", NULL, $2); $2->bro=$4; }
		;
ParamList 	: ExprList  	{ $$ = $1; }						
		|		{ $$ = NULL; }						
		;
ExprList 		: Expr ',' ExprList { $$ = $1; $1->bro = $3; }					
		| Expr { $$ = $1; }		
		;
RtnStmt 		: TRETURN '(' Expr ')'	{ $$ = createNode("RETURN",NULL , $3); }			
		;	
Cond 		: Cond TAND  Rel  	{ $$ = createNode("AND", NULL, $1); $1->bro=$3; }	
		| Cond TOR Rel 		{ $$ = createNode("OR", NULL, $1); $1->bro=$3; }				
		| TNOT Rel 		{ $$ = createNode("NOT", NULL, $2); }
		| Rel 			{ $$ = $1; }						
		;
Rel 		: Expr TLT Expr  	{ $$ = createNode("LT", NULL, $1); $1->bro=$3; }						
		| Expr TLE Expr 	{ $$ = createNode("LE", NULL, $1); $1->bro=$3; }						
		| Expr TGT Expr  	{ $$ = createNode("GT", NULL, $1); $1->bro=$3; }						
		| Expr TGE Expr 	{ $$ = createNode("GE", NULL, $1); $1->bro=$3; }						
		| Expr TASS Expr  	{ $$ = createNode("EQ", NULL, $1); $1->bro=$3; }							
		| Expr TNE Expr 	{ $$ = createNode("NE", NULL, $1); $1->bro=$3; }							
		;
Expr 		: Expr TPLUS Term { $$ = createNode("PLUS", NULL, $1); $1->bro=$3; }							
		| Expr TMINUS Term { $$ = createNode("MINUS", NULL, $1); $1->bro=$3; }				
		| Term { $$ = $1; }			
		;
Term 		: Term TMUL Fact { $$ = createNode("TIMES", NULL, $1); $1->bro=$3; }	
		| Term TDIV Fact { $$ = createNode("DIVIDE", NULL, $1); $1->bro=$3; }	
		| Fact { $$ = $1; }	
		;
Fact 		: Var { $$ = $1; }						
		| Number	 { $$ = $1; }		
          		| FuncCall { $$ = $1; }					
		| TMINUS Fact { $$ = createNode("NEG", NULL, $2);}		
		| '('  Expr  ')' { $$ = $2; }						
		;
FuncCall 		: Name '(' ParamList ')' { $$ = createNode("FCALL", NULL, $1); $1->bro=$3; }				
		;
Name 		: TWORD	{ $$=createNode("NAME", NULL, NULL); $$->value.sv = $1; }
		;
Number		: TNUMBER { $$=createNode("NUMBER", NULL, NULL); $$->value.dv = $1; }	
		;
%%
void main() {
	yyparse();
	traverse(rootNode);
}
Node* createNode(char * kind, Node* bro, Node* son) {
	Node * node;

	node = (Node*)malloc(sizeof(Node));
	strcpy(node->kind, kind);
	node->bro = bro;
	node->son = son;

	return node;
}

void traverse(Node *tr) {
	if(tr == NULL) return;
	const char *kind = tr->kind;
	if(!strcmp(kind,"NUMBER")){
		printf("ldc %f; ", tr->value.dv); 
	}
	else if(!strcmp(kind,"NAME")){
		printf("ldc p(%s); ind; ",tr->value.sv);
	}
	else if(!strcmp(kind,"PLUS")){
		traverse(tr->son); traverse(tr->son->bro); printf("add; ");
	}
	else if(!strcmp(kind,"MINUS")){
		traverse(tr->son); traverse(tr->son->bro); printf("sub; ");
	}
	else if(!strcmp(kind,"TIMES")){
		traverse(tr->son); traverse(tr->son->bro); printf("mul; ");
	}
	else if(!strcmp(kind,"DIVIDE")){
		traverse(tr->son); traverse(tr->son->bro); printf("div; ");
	}
	else if(!strcmp(kind,"NEG")){
		traverse(tr->son); printf("neg; ");
	}
	else if(!strcmp(kind,"ASSIGN")){
		printf("ldc p(%s); ", tr->son->value.sv);  traverse(tr->son->bro); printf("sto; ");
	}
	else if(!strcmp(kind,"COMP")){
		Node *node = tr->son; while(node!= NULL) { traverse(node); node=node->bro; }
	}
	else if(!strcmp(kind,"AND")){
		traverse(tr->son); traverse(tr->son->bro); printf("and; ");
	}
	else if(!strcmp(kind,"OR")){
		traverse(tr->son); traverse(tr->son->bro); printf("or; ");
	}
	else if(!strcmp(kind,"NOT")){
		traverse(tr->son); printf("not; ");
	}
	else if(!strcmp(kind,"EQ")){
		traverse(tr->son); traverse(tr->son->bro); printf("equ; ");
	}
	else if(!strcmp(kind,"GT")){
		traverse(tr->son); traverse(tr->son->bro); printf("gt; ");
	}
	else if(!strcmp(kind,"GE")){
		traverse(tr->son); traverse(tr->son->bro); printf("geq; ");
	}
	else if(!strcmp(kind,"LT")){
		traverse(tr->son); traverse(tr->son->bro); printf("lt; ");
	}
	else if(!strcmp(kind,"LE")){
		traverse(tr->son); traverse(tr->son->bro); printf("leq; ");
	}
	else if(!strcmp(kind,"NE")){
		traverse(tr->son); traverse(tr->son->bro); printf("ne; ");
	}
	else if(!strcmp(kind,"RETURN")){
		traverse(tr->son); printf("str 0; retf ");
	}
	else if(!strcmp(kind,"WHILE")){
		printf("l1: ");
		Node *cond = tr->son; traverse(cond);	
		printf("fjp l2; ");
		Node *stmt = tr->son->bro; traverse(stmt);
		printf("ujp l1; l2: ");
	}
	else if(!strcmp(kind,"FOR")){
		Node *assign = tr->son; traverse(assign);
		printf("l1: ");
		traverse(tr->son->son);
		Node *expr = assign->bro; traverse(expr);
		printf("leq; "); printf("fjp l2; ");
		Node *body = expr->bro; traverse(body);
		printf("ujp l1; l2: ");
	}
	else if(!strcmp(kind,"IF")){
		Node *cond = tr->son; traverse(cond);
		Node *stmt = cond->bro; Node *stmt2 = stmt->bro;
		printf("fjp ");
		if(stmt2 == NULL) { // if
			printf("l; ");
			traverse(stmt);
			printf("l: ");
		}
		else {		  // if - else
			printf("l1; ");
			traverse(stmt);
			printf("ujp l2; l1: ");
			traverse(stmt2);
			printf("l2: ");
		}
	}
	else if(!strcmp(kind,"SUBPGM")){
		Node *subpgm = tr->son;
		while(subpgm != NULL) {
			traverse(subpgm); subpgm=subpgm->bro;
		}
	}
	else if(!strcmp(kind,"VARDECL")){
		Node *decllist = tr->son;
		while(decllist != NULL) {
			traverse(decllist); decllist=decllist->bro;
		}
	}
	else if(!strcmp(kind,"DECL")){
		Node *var = tr->son;
		while(strcmp(var->kind,"INT") && strcmp(var->kind,"LONG")){
			var = var->bro; p++;
		}
	}
	else if(!strcmp(kind,"COMP")){
		Node *stmt = tr->son;
		while(stmt != NULL) {
			traverse(tr->bro); stmt = stmt->bro;
		}
	}
	else if(!strcmp(kind,"PROC")){
		printf("l_%s: ssp ",tr->son->value.sv);
		Node *param = tr->son->bro; traverse(param);
		Node *vardecl = tr->son->bro->bro; traverse(vardecl);
		printf("%d; ", p+2); p = 0;
		Node *comp = tr->son->bro->bro->bro; traverse(comp);
		printf("retp ");
	}
	else if(!strcmp(kind,"FUNC")){
		printf("l_%s: ssp ",tr->son->value.sv);
		Node *param = tr->son->bro->bro; traverse(param);
		Node *vardecl = param->bro; traverse(vardecl);
		printf("%d; ", p+2); p = 0;
		Node *comp = vardecl->bro; traverse(comp);
	}
	else if(!strcmp(kind,"PCALL")){
		printf("mst; "); int n = 0; Node *node = tr->son->bro;
		while(node != NULL) { traverse(node); node=node->bro; n++; }
		printf("cup %d l_%s; ", n, tr->son->value.sv); 
	}
	else if(!strcmp(kind,"MAIN")){
		Node *subpgm = tr->bro; traverse(subpgm);
		printf("ssp ");
		Node *vardecl = tr->son; traverse(vardecl);
		printf("%d; ", p+2); p = 0;
		Node *comp = tr->son->bro; traverse(comp);
		printf("stp");
	}
}