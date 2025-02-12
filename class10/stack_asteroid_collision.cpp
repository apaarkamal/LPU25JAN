class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		stack<int> St;
		for (int i = 0; i < asteroids.size(); i++) {
			if (asteroids[i] < 0) {
				bool exploded = false;
				while (!St.empty() && St.top() > 0) {
					if (abs(St.top()) == abs(asteroids[i])) {
						St.pop();
						exploded = true;
						break;
					}
					if (abs(St.top()) < abs(asteroids[i])) {
						St.pop();
						continue;
					}
					if (abs(St.top()) > abs(asteroids[i])) {
						exploded = true;
						break;
					}
				}
				if (!exploded) {
					St.push(asteroids[i]);
				}
			}
			else {
				St.push(asteroids[i]);
			}
		}
		vector<int> res;
		while (!St.empty()) {
			res.push_back(St.top());
			St.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};