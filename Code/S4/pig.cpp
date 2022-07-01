#include <bits/stdc++.h>
#define rep(i, s, t) for (int i = s; i <= t; i++)
using namespace std;

/* 全局变量 */
int n;                // 猪的数量
queue<char> allCards; // 牌堆

struct Pig
{
    /* 属性 */
    int index;                                                                                      // 当前猪下标
    int hp = 4;                                                                                     // 血量
    char type;                                                                                      // 猪的类型: M, Z, F
    char jumpType = 0;                                                                              // 跳的类型: Z(忠), F(反), f(MP视角的类反), 0(空), 注意对MP来说针对F更优先于f
    bool arming = false;                                                                            // 有无装备
    list<char> cards;                                                                               // 手中的牌
                                                                                                    /* 方法定义, 这里是完成本题必须的方法, 可以不必多定义了 */
    void jump() { jumpType = type == 'F' ? 'F' : 'Z'; }                                             // 跳阵营
    bool isJumpItsFriend(Pig *pig) { return pig->type == 'F' ? jumpType == 'F' : jumpType == 'Z'; } // 我跳它朋友了吗? 若该猪是反，那么我跳反则是朋友
    Pig *getNextPig();                                                                              // 获取存活的下家
    void addCards(int num);                                                                         // 从牌堆拿牌放到自己手右
    bool del(char c);                                                                               // 删掉手里一张牌, 删成功则返回true
    void hurt(Pig *attacker);                                                                       // 被攻击掉一点血
    bool cost(Pig *attacker, char c);                                                               // 被迫消耗手中一张牌, 消耗成功返回true并不减血, 否则减血, 减血到0尝试用桃, 无则死亡, 根据身份对杀者做后续处理
    bool useP();                                                                                    // 主动使用桃, 满足使用条件就使用, 使用后返回true
    bool useK();                                                                                    // 主动使用杀, 满足使用条件就使用, 使用后返回true
    bool useF();                                                                                    // 主动使用决斗, 满足使用条件就使用, 使用后返回true
    bool useN();                                                                                    // 主动使用南猪入侵, 满足使用条件就使用, 使用后返回true
    bool useW();                                                                                    // 主动使用万箭齐发, 满足使用条件就使用, 使用后返回true
    bool findJ(Pig *attacker);                                                                      // 被迫去求无懈可击, 求到则返回true
    bool useJ(Pig *pig);                                                                            // 帮某个猪用无懈可击, 用成功返回true
} ps[15];

/* 全局方法 */
bool isGameEnd()
{
    if (ps[0].hp <= 0)
        return true;
    rep(i, 1, n - 1) if (ps[i].type == 'F' && ps[i].hp > 0) return false;
    return true;
}
int cnt = 0;
void judgeGameEnd()
{
    if (isGameEnd())
    {
        // 结束则输出游戏结果
        printf(ps[0].hp > 0 ? "MP\n" : "FP\n");
        rep(i, 0, n - 1)
        {
            if (ps[i].hp <= 0)
            {
                printf("DEAD\n");
            }
            else
            {
                // 输出手牌
                for (list<char>::iterator it = ps[i].cards.begin(); it != ps[i].cards.end(); it++)
                    printf(it == ps[i].cards.end() ? "%c" : "%c ", *it);
                printf("\n");
            }
        }
        exit(0);
    }
}

void solve()
{
    ps[0].jump();   // 主猪表明阵营
    while (true)
    {
        rep(i, 0, n - 1)
        {
            if (ps[i].hp <= 0)
                continue;
            ps[i].addCards(2);
            bool usedK = false;
            for (list<char>::iterator it = ps[i].cards.begin(); it != ps[i].cards.end(); it++)
            {
                bool used = false;
                char c = *it;
                it = ps[i].cards.erase(it);     // 返回被删除元素的下一元素
                switch (c)
                {
                case 'P':
                    used = ps[i].useP();
                    break;
                case 'K':
                    if (!usedK || ps[i].arming)     // 未使用杀或者装备猪葛连弩
                        used = usedK = ps[i].useK();
                    break;
                case 'F':
                    used = ps[i].useF();
                    break;
                case 'N':
                    used = ps[i].useN();
                    break;
                case 'W':
                    used = ps[i].useW();
                    break;
                case 'Z':
                    ps[i].arming = used = true;
                    break;
                }
                // 若使用当前这张牌
                if (used)
                    it = --ps[i].cards.begin();     // 从头开始 it++ == begin()
                else
                    it = ps[i].cards.insert(it, c);
                
                if (ps[i].hp <= 0)
                    break;
            }
        }
    }
}
/* 主控方法 */
int main()
{
    #ifdef LOCAL
        freopen("e.in", "r", stdin);
        freopen("e.out", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    // Input
    int m;
    scanf("%d%d", &n, &m);
    char s[5];
    rep(i, 0, n - 1)
    {
        ps[i].index = i;
        // 遇到空格停止
        scanf("%s", s), ps[i].type = s[0];
        rep(j, 1, 4) scanf("%s", s), ps[i].cards.push_back(s[0]);
    }
    // 读入牌堆中的牌
    while (m--)
        scanf("%s", s), allCards.push(s[0]);
    // To solve
    solve();
}

Pig *Pig::getNextPig()
{
    int nxt = (index + 1) % n;
    while (ps[nxt].hp <= 0)
    {
        nxt = (nxt + 1) % n;
    }
    return &ps[nxt];
}

void Pig::addCards(int num)
{
    rep(i, 1, num)
    {
        cards.push_back(allCards.front());
        if (allCards.size() > 1) allCards.pop();
    }
}

bool Pig::useP()
{
    if (hp < 4)
    {
        hp++;
        return true;
    }
    return false;
}

bool Pig::useK()
{
    // TODO: 补全代码
    // 只能对攻击范围内的人使用(下家)
    // 攻击之前对敌我身份进行斟酌
    Pig *nxt = getNextPig();           // 攻击对象
    bool used = false;                 // 是否出杀

    if (this->type == 'M' || this->type == 'Z') {
        if (nxt->jumpType == 'F') {
            used = true;
        }
        if (this->type == 'M') {
            if (nxt->jumpType == 'f') {
                used = true;
            }
        }
    }
    else {
        if (nxt->jumpType == 'Z') {
            used = true;
        }
    }
    if (used) {
        this->jump();
        if (!nxt->del('D')) {
            nxt->hurt(this);
        }
        return true;
    }
    return false;
}

bool Pig::useF()
{
    // TODO: 补全代码
    // 忠猪会让着主猪
    // 攻击距离无限
    Pig *nxt;           // 攻击对象
    bool used = false;  // 是否打出该决斗

    // 确定决斗对象
    if (this->type == 'M' || this->type == 'Z') {
        nxt = getNextPig();
        do
        {
            if (nxt->jumpType == 'F') {
                used = true;
                break;
            }
            nxt = nxt->getNextPig();
        } while (nxt != this);

        if (!used) {
            nxt = getNextPig();
            if (this->type == 'M') {
                do
                {
                    if (nxt->jumpType == 'f') {
                        used = true;
                        break;
                    }
                    nxt = nxt->getNextPig();
                } while (nxt != this);
            }
        }
    }
    else {
        nxt = getNextPig();
        do
        {
            if (nxt->type == 'M') {     // 第1个跳Z阵营的为MP
                used = true;
                break;
            }
            nxt = nxt->getNextPig();
        } while (nxt != this);
        // 反猪F只向主猪使用
        /*if (!used) {
            nxt = getNextPig();
            do
            {
                if (nxt->jumpType == 'Z') {
                    used = true;
                    break;
                }
                nxt = nxt->getNextPig();
            } while (nxt != this);
        }*/
    }
    if (used) {
        this->jump();

        // 找人帮忙
        if (nxt->findJ(this)) {
            return true;    // 被无懈了
        }   
        /*if (this->findJ(nxt)) {
            return true;    // 被无懈了
        }*/

        if (this->type == 'M' && nxt->type == 'Z') {    // Z -> f,此时nxt未跳阵营
            nxt->hurt(this);
            return true;
        }

        while (true) {
            if (!nxt->del('K')) {
                nxt->hurt(this);
                break;
            }
            else if (this->type == 'M') {
                nxt->jump();
            }
            if (!this->del('K')) {
                this->hurt(nxt);
                break;
            }
        }
        return true;
    }
    return false;
}

bool Pig::useN()
{
    for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig())
    {
        // TODO: 补全代码
        if (nxt->findJ(this)) {
            continue;   // 被无懈了
        }
        if (!nxt->del('K')) {   // 出牌阶段除决斗外不会弃牌
            nxt->hurt(this);
            // 类反猪认定
            if (nxt->type == 'M') {
                if (this->jumpType == 0) {
                    this->jumpType = 'f';
                }
            }
        }
    }
    return true;
}

bool Pig::useW()
{
    for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig())
    {
        // TODO: 补全代码
        // 无懈在锦囊生效之前使用
        if (nxt->findJ(this)) {
            continue;   // 被无懈了
        }
        if (!nxt->del('D')) {
            nxt->hurt(this);
            // 类反猪认定
            if (nxt->type == 'M') {
                if (this->jumpType == 0) {
                    this->jumpType = 'f';
                }
            }
        }
    }
    return true;
}

bool Pig::del(char c)
{
    // TODO: 补全代码
    for (auto it = cards.begin(); it != cards.end(); it++) {
        if (c == *it) {
            cards.erase(it);
            return true;
        }
    }
    return false;
}

void Pig::hurt(Pig *attacker)
{
    if (--hp == 0)
    {
        // 濒死状态可以使用桃
        if (this->del('P'))
        {
            this->useP();
        }
        else
        {
            // 选手死亡之后判断游戏是否结束
            judgeGameEnd();
            switch (type)
            {
            case 'F':
                attacker->addCards(3);
                break;
            case 'Z':
                if (attacker->type == 'M')
                    attacker->cards.clear(), attacker->arming = false;
                break;
            }
        }
    }
}

bool Pig::cost(Pig *attacker, char c)
{
    if (this->del(c))
    {
        return true;
    }
    hurt(attacker);
    return false;
}

bool Pig::findJ(Pig *attacker)
{
    Pig *nxt = attacker;
    do
    {
        // "找个好心的猪猪帮我挡刀"
        if (this->isJumpItsFriend(nxt) && nxt->del('J'))
        {
            nxt->jump();
            return !nxt->useJ(this);
        }
        nxt = nxt->getNextPig();
    } while (nxt != attacker);
    return false;
}

bool Pig::useJ(Pig *pig)
{
    for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig())
    {
        // "套娃指找找有没有猪猪会阻止我帮别人挡刀"
        if (!this->isJumpItsFriend(nxt) && nxt->del('J'))
        {
            nxt->jump();
            return !pig->findJ(nxt);
        }
    }
    return false;
}
