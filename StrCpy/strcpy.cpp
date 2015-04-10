/**
 * 不适用库函数，实现strcpy
 * 要检查参数的合理性，
 * 还要考虑overlap问题
 */


/**
 * 标准答案
 * 但是如果考虑overlap问题，就要考虑
 * 1. src + n > des(尾->头)；
 * 2. des + n > src ，此时头->尾
 *          -----------------
 * ---------|--             |
 * |  src   | |   des       |
 * ---------|--             |
 *          -----------------
 *
 *          -----------------
 * ---------|--             |
 * |  des   | |   src       |
 * ---------|--             |
 *          -----------------
 *
 * 总而言之，覆盖了哪一部分，哪一部分先复制
 */

char* strcpy(char *strDest, const char *strSrc){
	if (strDest == strSrc)
	{
		return strDest;  //这是考虑重叠的一种情况，但是这是完全重叠，不靠谱
	}
	assert((strDest != NULL) && (strSrc != NULL));  //判断输入参数是否是空指针

	char *address;
	while((*strDest++ = *strSrc++) != '\0');
	//1.所有单目运算符具有相同优先级，右结合，故
	/**
	 * *strDest++  <==>  strDest++;
	 * 					 *strDest;
	 *
	 * 2.*strDest++ = *strSrc++ 执行完之后，相当于再判断 *strDest != '\0',
	 * 当 *strDest == '\0' ; 时，已经进行过 将 *strSrc == '\0' 复制过去了；
	 * 故保证了最后字符串完整'\0' 结尾
	 *
	 * while(*str != '\0'){ *strDest++ = *strSrc++; } 的话最后没有复制'\0'过去
	 */

	return address;  //复制完之后 strDest 指针指向 '\0' ，返回这个字符串已经不对了
					//返回 address 实现链式调用，比如: char* str = strcpy(des, src);

}

//得2分
void strcpy( char *strDest, char *strSrc )
{
    while( (*strDest++ = * strSrc++) != '\0' );
}

//得4分
void strcpy( char *strDest, const char *strSrc )
{
    //将源字符串加const，表明其为输入参数，加2分
    while( (*strDest++ = * strSrc++) != '\0' );
}

//得7分
void strcpy(char *strDest, const char *strSrc)
{
    //对源地址和目的地址加非0断言，加3分
    assert( (strDest != NULL) && (strSrc != NULL) );
    while( (*strDest++ = * strSrc++) != '\0' );
}

//得9分
//为了实现链式操作，将目的地址返回，加2分！
char * strcpy( char *strDest, const char *strSrc )
{
    assert( (strDest != NULL) && (strSrc != NULL) );
    char *address = strDest;
    while( (*strDest++ = * strSrc++) != '\0' );
    return address;
}

//得10分，基本上所有的情况，都考虑到了
//如果有考虑到源目所指区域有重叠的情况，加1分！
char * strcpy( char *strDest, const char *strSrc )
{
    if(strDest == strSrc) { return strDest; }
    assert( (strDest != NULL) && (strSrc != NULL) );
    char *address = strDest;
    while( (*strDest++ = * strSrc++) != '\0' );
    return address;
}
