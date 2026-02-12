class AuctionSystem {
private:
    unordered_map<int, unordered_map<int,int>> bids;
    unordered_map<int, set<pair<int,int>>> order;

public:
    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        if (bids[itemId].count(userId)) {
            int oldAmount = bids[itemId][userId];
            order[itemId].erase({-oldAmount, -userId});
        }

        bids[itemId][userId] = bidAmount;
        order[itemId].insert({-bidAmount, -userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmount = bids[itemId][userId];
        order[itemId].erase({-oldAmount, -userId});

        bids[itemId][userId] = newAmount;
        order[itemId].insert({-newAmount, -userId});
    }

    void removeBid(int userId, int itemId) {
        int oldAmount = bids[itemId][userId];
        order[itemId].erase({-oldAmount, -userId});
        bids[itemId].erase(userId);
    }

    int getHighestBidder(int itemId) {
        if (!order.count(itemId) || order[itemId].empty())
            return -1;

        return -order[itemId].begin()->second;
    }
};
