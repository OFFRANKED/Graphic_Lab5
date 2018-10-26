//***************************************************************************************
// GeometryGenerator.cpp by Frank Luna (C) 2011 All Rights Reserved.
//***************************************************************************************

#include "GeometryGenerator.h"
#include <algorithm>

using namespace DirectX;

XMVECTOR ComputeNormals(FXMVECTOR p0,FXMVECTOR p1, FXMVECTOR p2) {
	XMVECTOR U = p1 - p0;
	XMVECTOR V = p2 - p0;
	return XMVector3Normalize(XMVector3Cross(U, V));
}
GeometryGenerator::MeshData GeometryGenerator::CreateDiamond(float height, float widthTop) {
	MeshData meshData;

	Vertex v[17];

	float sw = sqrt((widthTop*widthTop) / 2);
	float hw = (widthTop*1.42857f);
	float hh = (height * 2) / 3;
	float shw = sqrt((hw*hw) / 2);
	v[0] = Vertex(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	v[1] = Vertex(0.0f, -hw, hh, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[2] = Vertex(shw, -shw, hh, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	v[3] = Vertex(hw, 0.0f, hh, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[4] = Vertex(shw, shw, hh, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[5] = Vertex(0.0f, hw, hh, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[6] = Vertex(-shw, shw, hh, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[7] = Vertex(-hw, 0.0f, hh, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[8] = Vertex(-shw, -shw, hh, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);//32

	v[9] = Vertex(-widthTop, 0.0f, height, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[10] = Vertex(-sw, -sw, height, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[11] = Vertex(0.0f, -widthTop, height, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[12] = Vertex(sw, -sw, height, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[13] = Vertex(widthTop, 0.0f, height, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[14] = Vertex(sw, sw, height, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[15] = Vertex(0.0f, widthTop, height, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[16] = Vertex(-sw, sw, height, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);//24

	for (int i = 0; i < 17; i++) {
		XMVECTOR p = XMLoadFloat3(&v[i].Position);
		
		XMStoreFloat3(&v[i].Normal, XMVector3Normalize(p));
	}
	meshData.Vertices.assign(&v[0], &v[17]);

	uint32 i[90];
	i[0] = 0; i[2] = 1; i[1] = 2;

	i[3] = 0; i[5] = 2; i[4] = 3;

	i[6] = 0; i[8] = 3; i[7] = 4;

	i[9] = 0; i[11] = 4; i[10] = 5;

	i[12] = 0; i[14] = 5; i[13] = 6;

	i[15] = 0; i[17] = 6; i[16] = 7;

	i[18] = 0; i[20] = 7; i[19] = 8;

	i[21] = 0; i[23] = 8; i[22] = 1;
	////////

	i[24] = 1; i[26] = 11; i[25] = 2;
	i[27] = 2; i[29] = 11; i[28] = 12;

	i[30] = 2; i[32] = 12; i[31] = 3;
	i[33] = 3; i[35] = 12; i[34] = 13;

	i[36] = 3; i[38] = 13; i[37] = 4;
	i[39] = 4; i[41] = 13; i[40] = 14;

	i[42] = 4; i[44] = 14; i[43] = 5;
	i[45] = 5; i[47] = 14; i[46] = 15;

	i[48] = 5; i[50] = 15; i[49] = 6;
	i[51] = 6; i[53] = 15; i[52] = 16;

	i[54] = 6; i[56] = 16; i[55] = 7;
	i[57] = 7; i[59] = 16; i[58] = 9;

	i[60] = 7; i[62] = 9; i[61] = 8;
	i[63] = 8; i[65] = 9; i[64] = 10;

	i[66] = 8; i[68] = 10; i[67] = 1;
	i[69] = 1; i[71] = 10; i[70] = 11;

	i[72] = 9; i[73] = 10; i[74] = 11; //top face
	i[75] = 11; i[76] = 12; i[77] = 13;
	i[78] = 13; i[79] = 14; i[80] = 15;
	i[81] = 15; i[82] = 16; i[83] = 9;
	i[84] = 11; i[85] = 15; i[86] = 9;
	i[87] = 11; i[88] = 13; i[89] = 15;
	meshData.Indices32.assign(&i[0], &i[90]);

	//for (int j = 0; j < 90; j += 3) {
	//	XMVECTOR temp1 = XMLoadFloat3(&v[i[j]].Position);
	//	XMVECTOR temp2 = XMLoadFloat3(&v[i[j + 1]].Position);
	//	XMVECTOR temp3 = XMLoadFloat3(&v[i[j + 2]].Position);

	//	XMVECTOR tempCombined1 =XMVectorSubtract(temp2, temp1);
	//	XMVECTOR tempCombined2 = XMVectorSubtract(temp3, temp1);
	//	XMVECTOR N = XMVector3Normalize(XMVector3Cross(tempCombined1, tempCombined2));
	//	
	//	temp1 = XMLoadFloat3(&v[i[j]].Normal);
	//	temp2 = XMLoadFloat3(&v[i[j+1]].Normal);
	//	temp3 = XMLoadFloat3(&v[i[j+2]].Normal);

	//	temp1 += N;
	//	temp2 += N;
	//	temp3 += N;
	//	//add result to normals of all 3
	//	XMStoreFloat3(&v[i[j]].Normal, XMVector3Normalize(temp1));
	//	XMStoreFloat3(&v[i[j+1]].Normal, XMVector3Normalize(temp2));
	//	XMStoreFloat3(&v[i[j+2]].Normal, XMVector3Normalize(temp3));
	//}

	

	return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreatePyramid(float height, float width) {
	MeshData meshData;

	Vertex v[5];

	v[0] = Vertex(0.0f, height, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//top
	v[1] = Vertex(-width, 0.0f, -width, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//bottom back left
	v[2] = Vertex(-width, 0.0f, width, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//bottom front left
	v[3] = Vertex(width, 0.0f, -width, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//bottom back right
	v[4] = Vertex(width, 0.0f, width, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//bottom front right

	meshData.Vertices.assign(&v[0], &v[5]);
	uint32 i[18];
	i[0] = 0; i[1] = 1; i[2] = 2;
	i[3] = 0; i[4] = 2; i[5] = 4;
	i[6] = 0; i[7] = 4; i[8] = 3;
	i[9] = 0; i[10] = 3; i[11] = 1;
	i[12] = 1; i[13] = 4; i[14] = 2;
	i[15] = 1; i[16] = 3; i[17] = 4;




	meshData.Indices32.assign(&i[0], &i[18]);
	return meshData;
}
GeometryGenerator::MeshData GeometryGenerator::CreateParrellegramPrism(float height, float width, float depth) {
	MeshData meshData;

	Vertex v[8];

	v[0] = Vertex(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//front left bot

	v[1] = Vertex(width*3/4, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f); //front right bot
	v[2] = Vertex(width/4, height, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);//front left top

	v[3] = Vertex(width, height, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);//front right top
	v[4] = Vertex(0.0f, 0.0f, depth, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back left bot
	v[5] = Vertex(width *3/4, 0.0f, depth, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);//back right bot
	v[6] = Vertex(width/4, height, depth, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back left top
	v[7] = Vertex(width, height, depth, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);//back right top

	
	meshData.Vertices.assign(&v[0], &v[8]);
	uint32 i[36];
	i[0] = 0; i[1] = 2; i[2] = 1;//front
	i[3] = 1; i[4] = 2; i[5] = 3;
	i[6] = 1; i[7] = 3; i[8] = 7;//right
	i[9] = 1; i[10] = 7; i[11] = 5;
	i[12] = 5; i[13] = 6; i[14] = 4;//back
	i[15] = 5; i[16] = 7; i[17] = 6;
	i[18] = 0; i[19] = 4; i[20] = 6;//left
	i[21] = 0; i[22] = 6; i[23] = 2;
	i[24] = 2; i[25] = 6; i[26] = 3;//top
	i[27] = 3; i[28] = 6; i[29] = 7;
	i[30] = 0; i[31] = 1; i[32] = 4;//bot
	i[33] = 1; i[34] = 5; i[35] = 4;


	meshData.Indices32.assign(&i[0], &i[36]);
	return meshData;
}



GeometryGenerator::MeshData GeometryGenerator::CreateBattlements(float height, float widthTall,float numBattlements ) {
	MeshData meshData;
	
	const int NUMVERT = 14;
	const int NUMINDICES = 72;
	float crenelHeight = (height * 2) / 3;
	float crenelWidth = (widthTall * 2) / 3;
	float totalWidth = crenelWidth + widthTall;
	for (int i = 0; i < numBattlements; i++) {
		Vertex v[NUMVERT];
		//create the tall box
		v[0] = Vertex(0.0f+(i *totalWidth), 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//front left bot
		v[1] = Vertex(widthTall+ (i *totalWidth), 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//front right bot
		v[2] = Vertex(0.0f+ (i *totalWidth), height, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//front left top
		v[3] = Vertex(widthTall+ (i *totalWidth), height, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//front right top
		v[4] = Vertex(0.0f+ (i *totalWidth), 0.0f, widthTall, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back left bot
		v[5] = Vertex(widthTall+ (i *totalWidth), 0.0f, widthTall, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back right bot
		v[6] = Vertex(0.0f+ (i *totalWidth), height, widthTall, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back left top
		v[7] = Vertex(widthTall+ (i *totalWidth), height, widthTall, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back right top
		//create the smaller box 
		v[8] = Vertex(widthTall + (i *totalWidth), crenelHeight, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//front left top 
		v[9] = Vertex(widthTall + (i *totalWidth), crenelHeight, widthTall, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back left top
		v[10] = Vertex(totalWidth + (i *totalWidth), 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//front bot right 
		v[11] = Vertex(totalWidth + (i *totalWidth), 0.0f, widthTall, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back right bot
		v[12] = Vertex(totalWidth + (i *totalWidth), crenelHeight, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//front right top
		v[13] = Vertex(totalWidth + (i *totalWidth), crenelHeight, widthTall, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back right top



		uint32 indices[NUMINDICES];//tall box
		indices[0] = 0; indices[1] = 2; indices[2] = 1;//front
		indices[3] = 1; indices[4] = 2; indices[5] = 3;
		indices[6] = 1; indices[7] = 3; indices[8] = 5;//right
		indices[9] = 7; indices[10] = 5; indices[11] = 3;
		indices[12] = 4; indices[13] = 5; indices[14] = 7;//back
		indices[15] = 4; indices[16] = 7; indices[17] = 6;
		indices[18] = 4; indices[19] = 2; indices[20] = 0;//left
		indices[21] = 4; indices[22] = 6; indices[23] = 2;
		indices[24] = 4; indices[25] = 1; indices[26] = 5;//bot
		indices[27] = 4; indices[28] = 0; indices[29] = 1;
		indices[30] = 2; indices[31] = 7; indices[32] = 3;//top
		indices[33] = 2; indices[34] = 6; indices[35] = 7;
		//small box
		indices[36] = 1; indices[37] = 8; indices[38] = 10;//front
		indices[39] = 10; indices[40] = 8; indices[41] = 12;
		indices[42] = 10; indices[43] = 12; indices[44] = 11;//right
		indices[45] = 13; indices[46] = 11; indices[47] = 12;
		indices[48] = 5; indices[49] = 11; indices[50] = 13;//back
		indices[51] = 5; indices[52] = 13; indices[53] = 9;
		indices[54] = 5; indices[55] = 8; indices[56] = 1;//left
		indices[57] = 5; indices[58] = 9; indices[59] = 8;
		indices[60] = 5; indices[61] = 10; indices[62] = 11;//bot
		indices[63] = 5; indices[64] = 1; indices[65] = 10;
		indices[66] = 8; indices[67] = 13; indices[68] = 12;//top
		indices[69] = 8; indices[70] = 9; indices[71] = 13;

		for (int vert = 0; vert < NUMVERT; vert++) {//for each set of battles push it to the meshdata
			meshData.Vertices.push_back(v[vert]);
		}
		for (int indic = 0; indic < NUMINDICES; indic++) {//for each set of indices offset it by the numvertices multiplied by which battlement piece we are making
			indices[indic] += i * NUMVERT;
			meshData.Indices32.push_back(indices[indic]);
		}
	}
	Vertex v[NUMVERT];//Create the last box in the battlement

	v[0] = Vertex(0.0f + (numBattlements *totalWidth), 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//front left bot
	v[1] = Vertex(widthTall + (numBattlements *totalWidth), 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//front right bot
	v[2] = Vertex(0.0f + (numBattlements *totalWidth), height, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//front left top
	v[3] = Vertex(widthTall + (numBattlements *totalWidth), height, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//front right top
	v[4] = Vertex(0.0f + (numBattlements *totalWidth), 0.0f, widthTall, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back left bot
	v[5] = Vertex(widthTall + (numBattlements *totalWidth), 0.0f, widthTall, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back right bot
	v[6] = Vertex(0.0f + (numBattlements *totalWidth), height, widthTall, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back left top
	v[7] = Vertex(widthTall + (numBattlements *totalWidth), height, widthTall, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);//back right top
	uint32 indices[NUMINDICES];
	indices[0] = 0; indices[1] = 2; indices[2] = 1;//front
	indices[3] = 1; indices[4] = 2; indices[5] = 3;
	indices[6] = 1; indices[7] = 3; indices[8] = 5;//right
	indices[9] = 7; indices[10] = 5; indices[11] = 3;
	indices[12] = 4; indices[13] = 5; indices[14] = 7;//back
	indices[15] = 4; indices[16] = 7; indices[17] = 6;
	indices[18] = 4; indices[19] = 2; indices[20] = 0;//left
	indices[21] = 4; indices[22] = 6; indices[23] = 2;
	indices[24] = 4; indices[25] = 1; indices[26] = 5;//bot
	indices[27] = 4; indices[28] = 0; indices[29] = 1;
	indices[30] = 2; indices[31] = 7; indices[32] = 3;//top
	indices[33] = 2; indices[34] = 6; indices[35] = 7;
	for (int vert = 0; vert < NUMVERT; vert++) {
		meshData.Vertices.push_back(v[vert]);
	}
	for (int indic = 0; indic < NUMINDICES; indic++) {
		indices[indic] += numBattlements * NUMVERT;
		meshData.Indices32.push_back(indices[indic]);
	}
	return meshData;
}


GeometryGenerator::MeshData GeometryGenerator::CreateWedge(float height, float width,float length) {
	MeshData meshData;

	Vertex v[6];

	v[0] = Vertex(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[1] = Vertex(width, height, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[2] = Vertex(width, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[3] = Vertex(0.0f, 0.0f, -length, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[4] = Vertex(width, height, -length, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[5] = Vertex(width, 0.0f, -length, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	meshData.Vertices.assign(&v[0], &v[6]);
	uint32 i[24];
	i[0] = 0; i[1] = 2; i[2] = 1;
	i[3] = 1; i[4] = 2; i[5] = 4;
	i[6] = 4; i[7] = 2; i[8] = 5;
	i[9] = 1; i[10] = 4; i[11] = 3;
	i[12] = 1; i[13] = 3; i[14] = 0;
	i[15] = 5; i[16] = 3; i[17] = 4;
	i[18] = 0; i[19] = 3; i[20] = 5;
	i[21] = 0; i[22] = 5; i[23] = 2;
	meshData.Indices32.assign(&i[0], &i[24]);
	return meshData;
}
GeometryGenerator::MeshData GeometryGenerator::CreateTetraHedron(float height, float width, float depth) {
	MeshData meshData;

	Vertex v[4];

	v[0] = Vertex(0.0f, height, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[1] = Vertex(-width, 0.0f, -depth, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[2] = Vertex(width, 0.0f, -depth, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[3] = Vertex(0.0f, 0.0f, depth, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);


	meshData.Vertices.assign(&v[0], &v[6]);
	uint32 i[12];
	i[0] = 0; i[1] = 2; i[2] = 1;
	i[3] = 1; i[4] = 3; i[5] = 0;
	i[6] = 2; i[7] = 0; i[8] = 3;
	i[9] = 2; i[10] = 3; i[11] = 1;

	meshData.Indices32.assign(&i[0], &i[24]);
	return meshData;
}


GeometryGenerator::MeshData GeometryGenerator::CreateBox(float width, float height, float depth, uint32 numSubdivisions)
{
    MeshData meshData;

    //
	// Create the vertices.
	//

	Vertex v[24];

	float w2 = 0.5f*width;
	float h2 = 0.5f*height;
	float d2 = 0.5f*depth;
    
	// Fill in the front face vertex data.
	v[0] = Vertex(-w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[1] = Vertex(-w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[2] = Vertex(+w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[3] = Vertex(+w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	// Fill in the back face vertex data.
	v[4] = Vertex(-w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[5] = Vertex(+w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[6] = Vertex(+w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[7] = Vertex(-w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Fill in the top face vertex data.
	v[8]  = Vertex(-w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[9]  = Vertex(-w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[10] = Vertex(+w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[11] = Vertex(+w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	// Fill in the bottom face vertex data.
	v[12] = Vertex(-w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[13] = Vertex(+w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[14] = Vertex(+w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[15] = Vertex(-w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Fill in the left face vertex data.
	v[16] = Vertex(-w2, -h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[17] = Vertex(-w2, +h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[18] = Vertex(-w2, +h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
	v[19] = Vertex(-w2, -h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	// Fill in the right face vertex data.
	v[20] = Vertex(+w2, -h2, -d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	v[21] = Vertex(+w2, +h2, -d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
	v[22] = Vertex(+w2, +h2, +d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
	v[23] = Vertex(+w2, -h2, +d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);

	meshData.Vertices.assign(&v[0], &v[24]);
 
	//
	// Create the indices.
	//

	uint32 i[36];

	// Fill in the front face index data
	i[0] = 0; i[1] = 1; i[2] = 2;
	i[3] = 0; i[4] = 2; i[5] = 3;

	// Fill in the back face index data
	i[6] = 4; i[7]  = 5; i[8]  = 6;
	i[9] = 4; i[10] = 6; i[11] = 7;

	// Fill in the top face index data
	i[12] = 8; i[13] =  9; i[14] = 10;
	i[15] = 8; i[16] = 10; i[17] = 11;

	// Fill in the bottom face index data
	i[18] = 12; i[19] = 13; i[20] = 14;
	i[21] = 12; i[22] = 14; i[23] = 15;

	// Fill in the left face index data
	i[24] = 16; i[25] = 17; i[26] = 18;
	i[27] = 16; i[28] = 18; i[29] = 19;

	// Fill in the right face index data
	i[30] = 20; i[31] = 21; i[32] = 22;
	i[33] = 20; i[34] = 22; i[35] = 23;

	meshData.Indices32.assign(&i[0], &i[36]);

    // Put a cap on the number of subdivisions.
    numSubdivisions = std::min<uint32>(numSubdivisions, 6u);

    for(uint32 i = 0; i < numSubdivisions; ++i)
        Subdivide(meshData);

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateSphere(float radius, uint32 sliceCount, uint32 stackCount)
{
    MeshData meshData;

	//
	// Compute the vertices stating at the top pole and moving down the stacks.
	//

	// Poles: note that there will be texture coordinate distortion as there is
	// not a unique point on the texture map to assign to the pole when mapping
	// a rectangular texture onto a sphere.
	Vertex topVertex(0.0f, +radius, 0.0f, 0.0f, +1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	Vertex bottomVertex(0.0f, -radius, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	meshData.Vertices.push_back( topVertex );

	float phiStep   = XM_PI/stackCount;
	float thetaStep = 2.0f*XM_PI/sliceCount;

	// Compute vertices for each stack ring (do not count the poles as rings).
	for(uint32 i = 1; i <= stackCount-1; ++i)
	{
		float phi = i*phiStep;

		// Vertices of ring.
        for(uint32 j = 0; j <= sliceCount; ++j)
		{
			float theta = j*thetaStep;

			Vertex v;

			// spherical to cartesian
			v.Position.x = radius*sinf(phi)*cosf(theta);
			v.Position.y = radius*cosf(phi);
			v.Position.z = radius*sinf(phi)*sinf(theta);

			// Partial derivative of P with respect to theta
			v.TangentU.x = -radius*sinf(phi)*sinf(theta);
			v.TangentU.y = 0.0f;
			v.TangentU.z = +radius*sinf(phi)*cosf(theta);

			XMVECTOR T = XMLoadFloat3(&v.TangentU);
			XMStoreFloat3(&v.TangentU, XMVector3Normalize(T));

			XMVECTOR p = XMLoadFloat3(&v.Position);
			XMStoreFloat3(&v.Normal, XMVector3Normalize(p));

			v.TexC.x = theta / XM_2PI;
			v.TexC.y = phi / XM_PI;

			meshData.Vertices.push_back( v );
		}
	}

	meshData.Vertices.push_back( bottomVertex );

	//
	// Compute indices for top stack.  The top stack was written first to the vertex buffer
	// and connects the top pole to the first ring.
	//

    for(uint32 i = 1; i <= sliceCount; ++i)
	{
		meshData.Indices32.push_back(0);
		meshData.Indices32.push_back(i+1);
		meshData.Indices32.push_back(i);
	}
	
	//
	// Compute indices for inner stacks (not connected to poles).
	//

	// Offset the indices to the index of the first vertex in the first ring.
	// This is just skipping the top pole vertex.
    uint32 baseIndex = 1;
    uint32 ringVertexCount = sliceCount + 1;
	for(uint32 i = 0; i < stackCount-2; ++i)
	{
		for(uint32 j = 0; j < sliceCount; ++j)
		{
			meshData.Indices32.push_back(baseIndex + i*ringVertexCount + j);
			meshData.Indices32.push_back(baseIndex + i*ringVertexCount + j+1);
			meshData.Indices32.push_back(baseIndex + (i+1)*ringVertexCount + j);

			meshData.Indices32.push_back(baseIndex + (i+1)*ringVertexCount + j);
			meshData.Indices32.push_back(baseIndex + i*ringVertexCount + j+1);
			meshData.Indices32.push_back(baseIndex + (i+1)*ringVertexCount + j+1);
		}
	}

	//
	// Compute indices for bottom stack.  The bottom stack was written last to the vertex buffer
	// and connects the bottom pole to the bottom ring.
	//

	// South pole vertex was added last.
	uint32 southPoleIndex = (uint32)meshData.Vertices.size()-1;

	// Offset the indices to the index of the first vertex in the last ring.
	baseIndex = southPoleIndex - ringVertexCount;
	
	for(uint32 i = 0; i < sliceCount; ++i)
	{
		meshData.Indices32.push_back(southPoleIndex);
		meshData.Indices32.push_back(baseIndex+i);
		meshData.Indices32.push_back(baseIndex+i+1);
	}

    return meshData;
}
 
void GeometryGenerator::Subdivide(MeshData& meshData)
{
	// Save a copy of the input geometry.
	MeshData inputCopy = meshData;


	meshData.Vertices.resize(0);
	meshData.Indices32.resize(0);

	//       v1
	//       *
	//      / \
	//     /   \
	//  m0*-----*m1
	//   / \   / \
	//  /   \ /   \
	// *-----*-----*
	// v0    m2     v2

	uint32 numTris = (uint32)inputCopy.Indices32.size()/3;
	for(uint32 i = 0; i < numTris; ++i)
	{
		Vertex v0 = inputCopy.Vertices[ inputCopy.Indices32[i*3+0] ];
		Vertex v1 = inputCopy.Vertices[ inputCopy.Indices32[i*3+1] ];
		Vertex v2 = inputCopy.Vertices[ inputCopy.Indices32[i*3+2] ];

		//
		// Generate the midpoints.
		//

        Vertex m0 = MidPoint(v0, v1);
        Vertex m1 = MidPoint(v1, v2);
        Vertex m2 = MidPoint(v0, v2);

		//
		// Add new geometry.
		//

		meshData.Vertices.push_back(v0); // 0
		meshData.Vertices.push_back(v1); // 1
		meshData.Vertices.push_back(v2); // 2
		meshData.Vertices.push_back(m0); // 3
		meshData.Vertices.push_back(m1); // 4
		meshData.Vertices.push_back(m2); // 5
 
		meshData.Indices32.push_back(i*6+0);
		meshData.Indices32.push_back(i*6+3);
		meshData.Indices32.push_back(i*6+5);

		meshData.Indices32.push_back(i*6+3);
		meshData.Indices32.push_back(i*6+4);
		meshData.Indices32.push_back(i*6+5);

		meshData.Indices32.push_back(i*6+5);
		meshData.Indices32.push_back(i*6+4);
		meshData.Indices32.push_back(i*6+2);

		meshData.Indices32.push_back(i*6+3);
		meshData.Indices32.push_back(i*6+1);
		meshData.Indices32.push_back(i*6+4);
	}
}

GeometryGenerator::Vertex GeometryGenerator::MidPoint(const Vertex& v0, const Vertex& v1)
{
    XMVECTOR p0 = XMLoadFloat3(&v0.Position);
    XMVECTOR p1 = XMLoadFloat3(&v1.Position);

    XMVECTOR n0 = XMLoadFloat3(&v0.Normal);
    XMVECTOR n1 = XMLoadFloat3(&v1.Normal);

    XMVECTOR tan0 = XMLoadFloat3(&v0.TangentU);
    XMVECTOR tan1 = XMLoadFloat3(&v1.TangentU);

    XMVECTOR tex0 = XMLoadFloat2(&v0.TexC);
    XMVECTOR tex1 = XMLoadFloat2(&v1.TexC);

    // Compute the midpoints of all the attributes.  Vectors need to be normalized
    // since linear interpolating can make them not unit length.  
    XMVECTOR pos = 0.5f*(p0 + p1);
    XMVECTOR normal = XMVector3Normalize(0.5f*(n0 + n1));
    XMVECTOR tangent = XMVector3Normalize(0.5f*(tan0+tan1));
    XMVECTOR tex = 0.5f*(tex0 + tex1);

    Vertex v;
    XMStoreFloat3(&v.Position, pos);
    XMStoreFloat3(&v.Normal, normal);
    XMStoreFloat3(&v.TangentU, tangent);
    XMStoreFloat2(&v.TexC, tex);

    return v;
}

GeometryGenerator::MeshData GeometryGenerator::CreateGeosphere(float radius, uint32 numSubdivisions)
{
    MeshData meshData;

	// Put a cap on the number of subdivisions.
    numSubdivisions = std::min<uint32>(numSubdivisions, 6u);

	// Approximate a sphere by tessellating an icosahedron.

	const float X = 0.525731f; 
	const float Z = 0.850651f;

	XMFLOAT3 pos[12] = 
	{
		XMFLOAT3(-X, 0.0f, Z),  XMFLOAT3(X, 0.0f, Z),  
		XMFLOAT3(-X, 0.0f, -Z), XMFLOAT3(X, 0.0f, -Z),    
		XMFLOAT3(0.0f, Z, X),   XMFLOAT3(0.0f, Z, -X), 
		XMFLOAT3(0.0f, -Z, X),  XMFLOAT3(0.0f, -Z, -X),    
		XMFLOAT3(Z, X, 0.0f),   XMFLOAT3(-Z, X, 0.0f), 
		XMFLOAT3(Z, -X, 0.0f),  XMFLOAT3(-Z, -X, 0.0f)
	};

    uint32 k[60] =
	{
		1,4,0,  4,9,0,  4,5,9,  8,5,4,  1,8,4,    
		1,10,8, 10,3,8, 8,3,5,  3,2,5,  3,7,2,    
		3,10,7, 10,6,7, 6,11,7, 6,0,11, 6,1,0, 
		10,1,6, 11,0,9, 2,11,9, 5,2,9,  11,2,7 
	};

    meshData.Vertices.resize(12);
    meshData.Indices32.assign(&k[0], &k[60]);

	for(uint32 i = 0; i < 12; ++i)
		meshData.Vertices[i].Position = pos[i];

	for(uint32 i = 0; i < numSubdivisions; ++i)
		Subdivide(meshData);

	// Project vertices onto sphere and scale.
	for(uint32 i = 0; i < meshData.Vertices.size(); ++i)
	{
		// Project onto unit sphere.
		XMVECTOR n = XMVector3Normalize(XMLoadFloat3(&meshData.Vertices[i].Position));

		// Project onto sphere.
		XMVECTOR p = radius*n;

		XMStoreFloat3(&meshData.Vertices[i].Position, p);
		XMStoreFloat3(&meshData.Vertices[i].Normal, n);

		// Derive texture coordinates from spherical coordinates.
        float theta = atan2f(meshData.Vertices[i].Position.z, meshData.Vertices[i].Position.x);

        // Put in [0, 2pi].
        if(theta < 0.0f)
            theta += XM_2PI;

		float phi = acosf(meshData.Vertices[i].Position.y / radius);

		meshData.Vertices[i].TexC.x = theta/XM_2PI;
		meshData.Vertices[i].TexC.y = phi/XM_PI;

		// Partial derivative of P with respect to theta
		meshData.Vertices[i].TangentU.x = -radius*sinf(phi)*sinf(theta);
		meshData.Vertices[i].TangentU.y = 0.0f;
		meshData.Vertices[i].TangentU.z = +radius*sinf(phi)*cosf(theta);

		XMVECTOR T = XMLoadFloat3(&meshData.Vertices[i].TangentU);
		XMStoreFloat3(&meshData.Vertices[i].TangentU, XMVector3Normalize(T));
	}

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateCylinder(float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount)
{
    MeshData meshData;

	//
	// Build Stacks.
	// 

	float stackHeight = height / stackCount;

	// Amount to increment radius as we move up each stack level from bottom to top.
	float radiusStep = (topRadius - bottomRadius) / stackCount;

	uint32 ringCount = stackCount+1;

	// Compute vertices for each stack ring starting at the bottom and moving up.
	for(uint32 i = 0; i < ringCount; ++i)
	{
		float y = -0.5f*height + i*stackHeight;
		float r = bottomRadius + i*radiusStep;

		// vertices of ring
		float dTheta = 2.0f*XM_PI/sliceCount;
		for(uint32 j = 0; j <= sliceCount; ++j)
		{
			Vertex vertex;

			float c = cosf(j*dTheta);
			float s = sinf(j*dTheta);

			vertex.Position = XMFLOAT3(r*c, y, r*s);

			vertex.TexC.x = (float)j/sliceCount;
			vertex.TexC.y = 1.0f - (float)i/stackCount;

			// Cylinder can be parameterized as follows, where we introduce v
			// parameter that goes in the same direction as the v tex-coord
			// so that the bitangent goes in the same direction as the v tex-coord.
			//   Let r0 be the bottom radius and let r1 be the top radius.
			//   y(v) = h - hv for v in [0,1].
			//   r(v) = r1 + (r0-r1)v
			//
			//   x(t, v) = r(v)*cos(t)
			//   y(t, v) = h - hv
			//   z(t, v) = r(v)*sin(t)
			// 
			//  dx/dt = -r(v)*sin(t)
			//  dy/dt = 0
			//  dz/dt = +r(v)*cos(t)
			//
			//  dx/dv = (r0-r1)*cos(t)
			//  dy/dv = -h
			//  dz/dv = (r0-r1)*sin(t)

			// This is unit length.
			vertex.TangentU = XMFLOAT3(-s, 0.0f, c);

			float dr = bottomRadius-topRadius;
			XMFLOAT3 bitangent(dr*c, -height, dr*s);

			XMVECTOR T = XMLoadFloat3(&vertex.TangentU);
			XMVECTOR B = XMLoadFloat3(&bitangent);
			XMVECTOR N = XMVector3Normalize(XMVector3Cross(T, B));
			XMStoreFloat3(&vertex.Normal, N);

			meshData.Vertices.push_back(vertex);
		}
	}

	// Add one because we duplicate the first and last vertex per ring
	// since the texture coordinates are different.
	uint32 ringVertexCount = sliceCount+1;

	// Compute indices for each stack.
	for(uint32 i = 0; i < stackCount; ++i)
	{
		for(uint32 j = 0; j < sliceCount; ++j)
		{
			meshData.Indices32.push_back(i*ringVertexCount + j);
			meshData.Indices32.push_back((i+1)*ringVertexCount + j);
			meshData.Indices32.push_back((i+1)*ringVertexCount + j+1);

			meshData.Indices32.push_back(i*ringVertexCount + j);
			meshData.Indices32.push_back((i+1)*ringVertexCount + j+1);
			meshData.Indices32.push_back(i*ringVertexCount + j+1);
		}
	}

	BuildCylinderTopCap(bottomRadius, topRadius, height, sliceCount, stackCount, meshData);
	BuildCylinderBottomCap(bottomRadius, topRadius, height, sliceCount, stackCount, meshData);

    return meshData;
}

void GeometryGenerator::BuildCylinderTopCap(float bottomRadius, float topRadius, float height,
											uint32 sliceCount, uint32 stackCount, MeshData& meshData)
{
	uint32 baseIndex = (uint32)meshData.Vertices.size();

	float y = 0.5f*height;
	float dTheta = 2.0f*XM_PI/sliceCount;

	// Duplicate cap ring vertices because the texture coordinates and normals differ.
	for(uint32 i = 0; i <= sliceCount; ++i)
	{
		float x = topRadius*cosf(i*dTheta);
		float z = topRadius*sinf(i*dTheta);

		// Scale down by the height to try and make top cap texture coord area
		// proportional to base.
		float u = x/height + 0.5f;
		float v = z/height + 0.5f;

		meshData.Vertices.push_back( Vertex(x, y, z, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, u, v) );
	}

	// Cap center vertex.
	meshData.Vertices.push_back( Vertex(0.0f, y, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f) );

	// Index of center vertex.
	uint32 centerIndex = (uint32)meshData.Vertices.size()-1;

	for(uint32 i = 0; i < sliceCount; ++i)
	{
		meshData.Indices32.push_back(centerIndex);
		meshData.Indices32.push_back(baseIndex + i+1);
		meshData.Indices32.push_back(baseIndex + i);
	}
}

void GeometryGenerator::BuildCylinderBottomCap(float bottomRadius, float topRadius, float height,
											   uint32 sliceCount, uint32 stackCount, MeshData& meshData)
{
	// 
	// Build bottom cap.
	//

	uint32 baseIndex = (uint32)meshData.Vertices.size();
	float y = -0.5f*height;

	// vertices of ring
	float dTheta = 2.0f*XM_PI/sliceCount;
	for(uint32 i = 0; i <= sliceCount; ++i)
	{
		float x = bottomRadius*cosf(i*dTheta);
		float z = bottomRadius*sinf(i*dTheta);

		// Scale down by the height to try and make top cap texture coord area
		// proportional to base.
		float u = x/height + 0.5f;
		float v = z/height + 0.5f;

		meshData.Vertices.push_back( Vertex(x, y, z, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, u, v) );
	}

	// Cap center vertex.
	meshData.Vertices.push_back( Vertex(0.0f, y, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f) );

	// Cache the index of center vertex.
	uint32 centerIndex = (uint32)meshData.Vertices.size()-1;

	for(uint32 i = 0; i < sliceCount; ++i)
	{
		meshData.Indices32.push_back(centerIndex);
		meshData.Indices32.push_back(baseIndex + i);
		meshData.Indices32.push_back(baseIndex + i+1);
	}
}

GeometryGenerator::MeshData GeometryGenerator::CreateGrid(float width, float depth, uint32 m, uint32 n)
{
    MeshData meshData;

	uint32 vertexCount = m*n;
	uint32 faceCount   = (m-1)*(n-1)*2;

	//
	// Create the vertices.
	//

	float halfWidth = 0.5f*width;
	float halfDepth = 0.5f*depth;

	float dx = width / (n-1);
	float dz = depth / (m-1);

	float du = 1.0f / (n-1);
	float dv = 1.0f / (m-1);

	meshData.Vertices.resize(vertexCount);
	for(uint32 i = 0; i < m; ++i)
	{
		float z = halfDepth - i*dz;
		for(uint32 j = 0; j < n; ++j)
		{
			float x = -halfWidth + j*dx;

			meshData.Vertices[i*n+j].Position = XMFLOAT3(x, 0.0f, z);
			meshData.Vertices[i*n+j].Normal   = XMFLOAT3(0.0f, 1.0f, 0.0f);
			meshData.Vertices[i*n+j].TangentU = XMFLOAT3(1.0f, 0.0f, 0.0f);

			// Stretch texture over grid.
			meshData.Vertices[i*n+j].TexC.x = j*du;
			meshData.Vertices[i*n+j].TexC.y = i*dv;
		}
	}
 
    //
	// Create the indices.
	//

	meshData.Indices32.resize(faceCount*3); // 3 indices per face

	// Iterate over each quad and compute indices.
	uint32 k = 0;
	for(uint32 i = 0; i < m-1; ++i)
	{
		for(uint32 j = 0; j < n-1; ++j)
		{
			meshData.Indices32[k]   = i*n+j;
			meshData.Indices32[k+1] = i*n+j+1;
			meshData.Indices32[k+2] = (i+1)*n+j;

			meshData.Indices32[k+3] = (i+1)*n+j;
			meshData.Indices32[k+4] = i*n+j+1;
			meshData.Indices32[k+5] = (i+1)*n+j+1;

			k += 6; // next quad
		}
	}

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateQuad(float x, float y, float w, float h, float depth)
{
    MeshData meshData;

	meshData.Vertices.resize(4);
	meshData.Indices32.resize(6);

	// Position coordinates specified in NDC space.
	meshData.Vertices[0] = Vertex(
        x, y - h, depth,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f);

	meshData.Vertices[1] = Vertex(
		x, y, depth,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f);

	meshData.Vertices[2] = Vertex(
		x+w, y, depth,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f);

	meshData.Vertices[3] = Vertex(
		x+w, y-h, depth,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f);

	meshData.Indices32[0] = 0;
	meshData.Indices32[1] = 1;
	meshData.Indices32[2] = 2;

	meshData.Indices32[3] = 0;
	meshData.Indices32[4] = 2;
	meshData.Indices32[5] = 3;

    return meshData;
}
