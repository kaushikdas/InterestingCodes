## Initialization

```c++
class Wallet {
public:
  explicit Wallet(int cash)
};

int main() {
  // Wallet w = 50;  // ERROR

  Wallet w = static_cast<Wallet>(50);
}
```
