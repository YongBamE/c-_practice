#pragma once
#include<iostream>
#include<string.h>

using namespace std;



class City
{

private:
	int data[11];	//1.터널위 2.교량위 3. 고가도로위 4.하차도 5. 기타단일로 6. 교차로내 7. 차로횡단보도 8. 교차로부근 9. 철길건널목 10. 기타 11. 불명
	string cityName;
	string districtName;
public:
	City();
	City(const char* getname);

	string getCityName();
	string getDistrictName();
	int* getData();
	
	void setCityName(string name);
	void setDistrictName(string name);
	void setData(int i, string data);

};

// 도시별 자살인구

//도시명으로 다 찾아보고 없으면 그때 시군구 만약 띄어쓰기 있으면 둘다

// 1.시군구 선택
// 2.사망유형선택 or all
// 3.출력.끝.


//line 추출해서 전부 data[13]으로 만들기
//data[0]과 data[1]과 검색결과가 겹치는거 있으면 됨. 둘중하나라도 같으면 출력.
//나머지 data들은 숫자별로 나누고 입력하면 그쪽 데이터 출력되도록.
//이중포인터 만들어서 line 개수만큼 도시를 받아서 데이터 저장하는 인스턴스

//근데 이걸 클라스로 어떻게 나누지;
//1.City 인스턴스를 만들어서 search의 이름을 받는다.
//1.1 맞는 City 이름인지 확인해주는 함수. 일치하는것이 있으면 true 반환

//2. City를 받아서 사망자 받아주는 클래스

//도시에 정보를 담아야할까?
//도시이름만 받아서 데이터를 뽑아주는 클래스를 해야할까?

//시군구를 선택해서 이름을 고르면


//City 인스턴스를 229개 만들어놓고 거기 값들을 다 넣어버리기.
