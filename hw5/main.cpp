#include <iostream>
#include  "Mixed.h"
using namespace std;
int main(){
		Mixed x(1,1,1);
		Mixed y(1,1,1);
		char buf[10];
		
		cout << "Please enter first number x: ";
		cin >> x;
		cout << "Please enter second numbber y: ";
		cin >> y;
		
		cout << "You entered:\n";
		cout << "x = " << x;
		cout << "y = " << y;
		
		while(1){
				int option;
				cout << "(1)Evaluate\n(2)Simplify\n(3)ToFraction (4)Comparison (5)Arithmetic (6)Increment amd Decrement (7)Exit: ";
				cin >> option;

				if(option ==1){
						cout << "Decimal equivalent of x is: " << x.Evaluate() << endl;
						cout << "Decimal equivalent of y is: " << y.Evaluate() << endl;
				}
				else if(option == 2){
						x.Simplify();
						y.Simplify();
						cout << "x simplified = " << x;
						cout << "y simplified = " << y;
				}
				else if(option == 3){
						x.ToFraction();
						y.ToFraction();
						cout << "x simplified = " << x;
						cout << "y simplified = " << y;
				}
				else if(option == 4){
						while(1){
								cout << "(1)Insert two object to compare (2)Exit: ";
								int option_2;
								cin >> option_2;
								if(option_2 == 1){
										x.ToFraction();
										y.ToFraction();
										cin.ignore(256,'\n');
										char buf_2[20] = {'\0'};
										int a=0, b=0, c=0;
										char a_1[5]={'\0'}, b_1[5] = {'\0'}, c_1[10] = {'\0'};
										cin.getline(buf_2,20);
										cout << "buf = " << buf_2 << endl;
										if(sscanf(buf_2,"%s%s%d%s",a_1,b_1,&a,c_1) == 4){
												char *ptr = c_1;
												bool ans;
												
												while((*ptr)!='/')
														ptr++;
												*ptr = ' ';
												sscanf(c_1,"%d%d",&b,&c);
												Mixed tmp(a,b,c);
												if(strcmp(a_1,"x") == 0){
														if(strcmp(b_1,"<") == 0)
																ans = (x < tmp);
														else if(strcmp(b_1,">") == 0)
																ans = (x > tmp);
														else if(strcmp(b_1,"<=") == 0)
																ans = (x <= tmp);
														else if(strcmp(b_1,">=") == 0)
																ans = (x >= tmp);
														else if(strcmp(b_1,"==") == 0)
																ans = (x == tmp);
														else if(strcmp(b_1,"!=") == 0)
																ans = (x != tmp);
												}
												else if(strcmp(a_1,"y") == 0){
														if(strcmp(b_1,"<") == 0)
																ans = (y < tmp);
																else if(strcmp(b_1,">") == 0)
																		ans = (y > tmp);
																else if(strcmp(b_1,"<=") == 0)
																		ans = (y <= tmp);
																else if(strcmp(b_1,">=") == 0)
																		ans = (y >= tmp);
																else if(strcmp(b_1,"==") == 0)
																		ans = (x == tmp);
																else if(strcmp(b_1,"!=") == 0)
																		ans = (x != tmp);
												}
												else if(strcmp(a_1,"y") == 0){
														if(strcmp(b_1,"<") == 0)
																ans = (y < tmp);
														else if(strcmp(b_1,">") == 0)
																ans = (y > tmp);
														else if(strcmp(b_1,"<=") == 0)
																ans = (y <= tmp);
														else if(strcmp(b_1,">=") == 0)
																ans = (y >= tmp);
														else if(strcmp(b_1,"==") == 0)
																ans = (y == tmp);
														else if(strcmp(b_1,"!=") == 0)
																ans = (y != tmp);
												}
												if(ans == true)
														cout << "Yes" << endl;
												else 
														cout << "No" << endl;

										}
										else if(sscanf(buf_2,"%s%s%s",a_1,b_1,c_1) == 3){
												bool ans;
												if(isdigit(c_1[0])||isdigit(c_1[1])){
														Mixed tmp(atoi(c_1));
														if(strcmp(a_1,"x") == 0){
																if(strcmp(b_1,"<") == 0)
																		ans = (x < tmp);
																else if(strcmp(b_1,">") == 0)
																		ans = (x > tmp);
																else if(strcmp(b_1,"<=") == 0)
																		ans = (x <= tmp);
																else if(strcmp(b_1,">=") == 0)
																		ans = (x >= tmp);
																else if(strcmp(b_1,"==") == 0)
																		ans = (x == tmp);
																else if(strcmp(b_1,"!=") == 0)
																		ans = (x != tmp);
														}
														else if(strcmp(a_1,"y") == 0){
																if(strcmp(b_1,"<") == 0)
																		ans = (y < tmp);
																else if(strcmp(b_1,">") == 0)
																		ans = (y > tmp);
																else if(strcmp(b_1,"<=") == 0)
																		ans = (y <= tmp);
																else if(strcmp(b_1,">=") == 0)
																		ans = (y >= tmp);
																else if(strcmp(b_1,"==") == 0)
																		ans = (y == tmp);
																else if(strcmp(b_1,"!=") == 0)
																		ans = (y != tmp);
														}
														else{
																if(strcmp(a_1,"x") == 0){
																		if(strcmp(b_1,"<") == 0)
																				ans = (x < y);
																		else if(strcmp(b_1,">") == 0)
																				ans = (x > y);
																		else if(strcmp(b_1,"<=") == 0)
																				ans = (x <= y);
																		else if(strcmp(b_1,">=") == 0)
																				ans = (x >= y);
																		else if(strcmp(b_1,"==") == 0)
																				ans = (x == y);
																		else if(strcmp(b_1,"!=") == 0)
																				ans = (x != y);
																}
																else if(strcmp(a_1,"y") == 0){
																		if(strcmp(b_1,"<") == 0)
																				ans = (y < x);
																		else if(strcmp(b_1,">") == 0)
																				ans = (y > x);
																	    else if(strcmp(b_1,"<=") == 0)
																	    		ans = (y <= x);
																	    else if(strcmp(b_1,">=") == 0)
																	    		ans = (y >= x);
																	    else if(strcmp(b_1,"==") == 0)
																	    		ans = (y == x);
																	    else if(strcmp(b_1,"!=") == 0)
																	    		ans = (y != x);
																}
														}
														if(ans == true)
																cout << "Yes" << endl;
														else
																cout << "No" << endl;
												}
												else
														continue;
										}
								}
								else if(option_2 == 2)
										break;
						}
				}
						else if(option == 5){
								while(1){
										cout << "(1)Insert two object to do arithemtic (2)Exit: ";
										int option_2;
										cin >> option_2;
										if(option_2 == 1){
												x.ToFraction();
												y.ToFraction();
												cin.ignore(256,'\n');
												char buf_2[20] = {'\0'};
												int a=0, b=0, c=0;
												char a_1[5] = {'\0'},b_1[5] = {'\0'},c_1[5] = {'\0'};
												cin.getline(buf_2,20);
												if(sscanf(buf_2,"%s%s%d%s",a_1,b_1,&a,c_1) == 4){
														char *ptr = c_1;
														while((*ptr) != '/')
																ptr++;
														*ptr = ' ';
														sscanf(c_1,"%d%d",&b,&c);
														Mixed tmp(a,b,c);
														if(strcmp(a_1,"x") == 0){
																if(strcmp(b_1,"+") == 0){
																		Mixed ans = x + tmp;
																		cout << ans;
																}
																else if(strcmp(b_1,"-") == 0){
																		Mixed ans = x - tmp;
																		cout << ans;
																}
																else if(strcmp(b_1,"*") == 0){
																		Mixed ans = x*tmp;
																		cout << ans;
																}
																else if(strcmp(b_1,"/") == 0){
																		Mixed ans = x/tmp;
																		cout << ans;
																}
														}
														else if(strcmp(a_1,"y") == 0){
																if(strcmp(b_1,"+") == 0){
																		Mixed ans = y+tmp;
																		cout << ans;
																}
																else if(strcmp(b_1,"-") == 0){
																		Mixed ans = y-tmp;
																		cout << ans;
																}
																else if(strcmp(b_1,"*") == 0){
																		Mixed ans = y*tmp;
																		cout << ans;
																}
																else if(strcmp(b_1,"/") == 0){
																		Mixed ans = y/tmp;
																		cout << ans;
																}
														}
												}
												else if(sscanf(buf_2,"%s%s%s",a_1,b_1,c_1) == 3){
														if(isdigit(c_1[0])||isdigit(c_1[1])){
																Mixed tmp(atoi(c_1));
																if(strcmp(a_1,"x") == 0){
																		if(strcmp(b_1,"+") == 0){
																				Mixed ans = x+tmp;
																				cout << ans;
																		}
																		else if(strcmp(b_1,"-") == 0){
																				Mixed ans = x-tmp;
																				cout << ans;
																		}
																		else if(strcmp(b_1,"/") == 0){
																				Mixed ans = y+tmp;
																				cout << ans;
																		}
																
																}
														}
														else{
																if(strcmp(a_1,"x") == 0){
																		if(strcmp(b_1,"+") == 0){
																				Mixed ans = x+y;
																				cout << ans;
																		}
																		else if(strcmp(b_1,"-") == 0){
																				Mixed ans = x-y;
																				cout << ans;
																		}
																		else if(strcmp(b_1,"*") == 0){
																				Mixed ans = x*y;
																				cout << ans;
																		}
																		else if(strcmp(b_1,"/") == 0){
																				Mixed ans = x/y;
																				cout << ans;
																		}
																}
																else if(strcmp(a_1,"y") == 0){
																		if(strcmp(b_1,"+") == 0){
																				Mixed ans = y+x;
																				cout << ans;
																		}
																		else if(strcmp(b_1,"-") == 0){
																				Mixed ans = y-x;
																				cout << ans;
																		}
																		else if(strcmp(b_1,"*") == 0){
																				Mixed ans = y*x;
																				cout << ans;
																		}
																		else if(strcmp(b_1,"/") == 0){
																				Mixed ans = y/x;
																				cout << ans;
																		}
																}
														}
												}
										}
										else if(option == 2){
												break;
										}
								}
						}
						else if(option == 6){
								while(1){
										cout << "(1)Insert two object to do arithmetic (2)Exit : ";
										int option_2;
										cin >> option_2;
										if(option_2 == 1){
												cin.ignore(256,'\n');
												char buf_2[10] = {'\0'};
												cin.getline(buf_2,20);
												if(strcmp(buf_2,"++x") == 0){
														cout << "++x:" << ++x;
														cout << "x is now: " << x;
												}
												else if(strcmp(buf_2,"--x") == 0){
														cout << "--x:" << --x;
														cout << "x is now: " << --x;
												}
												else if(strcmp(buf_2,"++y") == 0){
														cout << "++y:" << ++y;
														cout << "y is now: " << y;
												}
												else if(strcmp(buf_2,"++y") == 0){
														cout << "++y:" << ++y;
														cout << "y is now: " << y;
												}
												if(strcmp(buf_2,"x++") == 0){
														cout << "x++:" << x++;
														cout << "x is now: " << x;
												}
												if(strcmp(buf_2,"x--") == 0){
														cout << "x--:" << x--;
														cout << "x is now: " << x;
												}
												if(strcmp(buf_2,"y++") == 0){
														cout << "y++:" << y++;
														cout << "y is now: " << y;
												}
												if(strcmp(buf_2,"y--") == 0){
														cout << "y--:" << y--;
														cout << "y is now: " << y;
												}
										}
								}
						}
								else if(option == 7)
										break;
						
				}
									
		return 0;
}
