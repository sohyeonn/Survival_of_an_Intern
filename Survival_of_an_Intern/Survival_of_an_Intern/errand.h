#pragma once
char *NPCerrandType[7] =
{ { "오부장: 윤인턴! 커피 좀 타와봐~" },//O
{ "오부장: 이봐 윤씨 ! 팩스 좀 보내~ !" },//O
{ "오부장: 윤인턴! 휴지통 좀 비우게!" },//O
{ "오부장: 윤인턴! 가서 자료 복사해와~ !" },//O
{ "오부장: 미스 윤 ~ 인쇄한거 팩스보내 ~ !" },//O
{ "구과장: 윤인턴! 이것 좀 부탁하네!" },//O
{ "채대리: 윤인턴~ 이것 좀 부탁해~" } };//
char *Buff_e[7] =
{ { "오부장: 아까 피곤해 보이던데 자네 마셔" },//npc정지
{ "오부장: 중요한 계약이었는데 수고했네~" },//보너스
{ "오부장: 근데 김사원은 왜 자꾸 윤인턴 따라다니나??" },//npc정지
{ "오부장: 고마워ㅎㅎ내 한턱 쏘지!" },//보너스
{ "오부장: 오 이걸 한 번에 해내다니 훌륭해~!" },//보너스
{ "구과장: 다음에 또 볼수도 있을 거 같군ㅎㅎ" },//친밀도 증가
{ "채대리: 가르친 보람이 있구만!" } };//친밀도 증가
char *Buff[7] =
{ { "( 김사원에게 커피를 뿌렸습니다. ( npc정지 ))" },//npc정지
{ "( 보너스를 받았어요! ( 보너스 +0.5만원 ))" },//월급감소
{ "( 김사원에게 쓰레기를 뿌렸습니다. ( npc정지 ))" },//npc정지
{ "( 보너스를 받았어요! ( 보너스 +0.5만원 ))" },//보너스
{ "( 보너스를 받았어요! ( 보너스 +0.5만원 ))" },//보너스
{ "( 구과장에게 귀여움을 받았습니다. ( 친밀도 상승 ))" },//친밀도 증가
{ "( 채대리의 신임을 얻었습니다. ( 친밀도 상승 ))" } };//친밀도 증가
char *Debuff_e[7] =
{ { "오부장: 자네는 커피 한 번을 안타봤나? 김사원한테 배워!" },//npc속도증가
{ "오부장: 에휴..자네 때문에 계약이 엉망이됐네.." },//월급감소
{ "오부장: 어이 김사원! 윤인턴이랑 같이 청소 좀 하게!" },//npc속도증가
{ "오부장: 김사원!! 여기와서 윤인턴 좀 가르치게!!" },//npc속도증가
{ "오부장: 아니 자네 때문에 계약 하나 놓쳤잖아! 책임져!!" },//월급감소
{ "구과장: 이거 안했네? 그럼 프로젝트에 내 이름 적어줘!" },//월급감소
{ "채대리: 우리 윤인턴 덕분에 나 과장 되기는 글렀네~" } };//npc속도증가
char *Debuff[7] =
{ { "( 김사원의 따라다니기 속도가 증가했습니다. )" },//npc속도증가
{ "( 월급을 뺐겼습니다. )" },//월급감소
{ "( 김사원의 따라다니기 속도가 증가했습니다. )" },//npc속도증가
{ "( 김사원의 따라다니기 속도가 증가했습니다. )" },//npc속도증가
{ "( 월급을 뺐겼습니다. )" },//월급감소
{ "( 월급을 뺐겼습니다. )" },//월급감소
{ "( 김사원의 따라다니기 속도가 증가했습니다.)" } };//npc속도증가
int NPCerrand_occur[7] = { 0,0,0,0,0,0,0 };
clock_t NPC_start[7];
clock_t NPC_end[7];
double NPC_duration[7] = { 0.0 };