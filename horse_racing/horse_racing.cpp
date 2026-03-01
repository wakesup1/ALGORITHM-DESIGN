#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ---------------------------------------------------------
// กรณีที่ 1: K = 2 (มี 2 สนาม, สนามละ N ตัว)
// วิธีคิด: สร้าง Combination ของม้า N ตัว โดยบังคับให้ม้าเบอร์ 1 อยู่สนามแรกเสมอ
// เพื่อจับคู่กับม้าที่เหลือในสนามที่ 2
// ---------------------------------------------------------
int N_val;
int Total_Horses;
vector<int> current_track1;
vector<bool> used;

void generate_k2(int start_num, int count) {
    // Base Case: เมื่อเลือกม้าครบ N ตัวสำหรับสนาม 1 แล้ว
    if (count == N_val) {
        // 1. พิมพ์สนามที่ 1
        // (ซึ่งมีเลข 1 อยู่เสมอ เพราะเราเริ่มเรียกฟังก์ชันด้วยเลข 1)
        for (int i = 0; i < N_val; i++) {
            cout << current_track1[i] << (i == N_val - 1 ? "" : " ");
        }
        cout << " "; // เว้นวรรคระหว่างสนาม

        // 2. หาม้าที่เหลือไปใส่สนามที่ 2
        // สร้าง vector เช็คว่าตัวไหนยังไม่ถูกเลือก
        vector<bool> is_in_track1(Total_Horses + 1, false);
        for (int h : current_track1) is_in_track1[h] = true;

        bool first = true;
        for (int i = 1; i <= Total_Horses; i++) {
            if (!is_in_track1[i]) {
                if (!first) cout << " ";
                cout << i;
                first = false;
            }
        }
        cout << endl; // จบบรรทัด (จบรอบ)
        return;
    }

    // Recursive: เลือกตัวเลขถัดไปมาใส่
    for (int i = start_num; i <= Total_Horses; i++) {
        current_track1.push_back(i);
        generate_k2(i + 1, count + 1);
        current_track1.pop_back(); // Backtrack
    }
}

void solve_k2(int n) {
    N_val = n;
    Total_Horses = 2 * n;
    
    // บังคับให้ม้าตัวที่ 1 อยู่สนามแรกเสมอ เพื่อลดงานลงครึ่งหนึ่ง (ตัด Symmetry)
    current_track1.push_back(1);
    
    // ไปหาอีก n-1 ตัว โดยเริ่มหาจากเลข 2
    generate_k2(2, 1);
}

// ---------------------------------------------------------
// กรณีที่ 2: N = 2 (สนามละ 2 ตัว, มี K สนาม)
// วิธีคิด: Round Robin Tournament (Circle Method)
// ตรึงเลข 1 ไว้ แล้วหมุนตัวเลขที่เหลือเป็นวงกลม
// ---------------------------------------------------------
void solve_n2(int k) {
    int total = 2 * k;
    
    // สร้าง Array ม้า [1, 2, 3, ..., 2k]
    vector<int> horses(total);
    iota(horses.begin(), horses.end(), 1);

    // จำนวนรอบทั้งหมดของการแข่งแบบพบกันหมดคือ Total - 1
    int rounds = total - 1;

    for (int r = 0; r < rounds; r++) {
        // ในแต่ละรอบ จับคู่หัว-ท้าย ของวงกลม
        
        // คู่แรก: ตัวที่ตรึงไว้ (index 0) เจอตัวที่หมุนมาใหม่ (index 0 ของวงหมุน)
        // เพื่อความง่าย เราจัดการ Array โดยตรงเลย
        
        for (int i = 0; i < k; i++) {
            int p1 = horses[i];
            int p2 = horses[total - 1 - i];
            
            // พิมพ์คู่ม้า (เรียงน้อยไปมากเสมอเพื่อความสวยงาม)
            cout << min(p1, p2) << " " << max(p1, p2);
            
            if (i < k - 1) cout << " "; // เว้นวรรคระหว่างคู่
        }
        cout << endl;

        // หมุนวงกลม (Circle Rotation)
        // เก็บตัวที่ 1 ไว้ที่เดิม (horses[0])
        // ตัวสุดท้ายย้ายมาเป็นตัวที่ 2
        // ตัวอื่นๆ ขยับไปขวา
        int last = horses.back();
        for (int i = total - 1; i > 1; i--) {
            horses[i] = horses[i - 1];
        }
        horses[1] = last;
    }
}

int main() {
    int k, n;
    // รับค่า K และ N
    if (cin >> k >> n) {
        if (k == 2) {
            solve_k2(n);
        } else {
            // โจทย์บอกว่าถ้า k!=2 ก็จะเป็น n=2 แน่นอน
            solve_n2(k); 
        }
    }
    return 0;
}