#ifndef PARSER_H
#define PARSER_H

#include <vector>

#include "parser/Lexer.h"

class Expr;
class Stmt;

class Parser {
public:
  Parser();

public:
  std::vector<Stmt *> parse(const std::vector<Token> &tokens, std::istream &input);

private:
  Stmt *parseStmt();
  Expr *parseExpr(int i = 0);
  Expr *parsePrimaryExpr();

  Token next();
  Token peek(int o = 0);
  Token require(TokenKind kind);
  bool is_a(TokenKind kind, int o = 0);

  std::string toString(Token t);
  int toInt(Token t);

private:
  int position;
  std::vector<Token> tokens;
  std::vector<int> precedence;
  std::istream *inputStream;
};

#endif // PARSER_H
