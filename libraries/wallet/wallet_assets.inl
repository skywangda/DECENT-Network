
vector<asset_object> wallet_api::list_assets(const string& lowerbound, uint32_t limit)const
{
   return my->_remote_db->list_assets( lowerbound, limit );
}

asset_object wallet_api::get_asset(string asset_name_or_id) const
{
   auto a = my->find_asset(asset_name_or_id);
   FC_ASSERT(a);
   return *a;
}

monitored_asset_options wallet_api::get_monitored_asset_data(string asset_name_or_id) const
{
   auto asset = get_asset(asset_name_or_id);
   FC_ASSERT(asset.is_monitored_asset() );
   return *asset.monitored_asset_opts;
}

signed_transaction wallet_api::create_monitored_asset(string issuer,
                                                      string symbol,
                                                      uint8_t precision,
                                                      string description,
                                                      uint32_t feed_lifetime_sec,
                                                      uint8_t minimum_feeds,
                                                      bool broadcast)

{
   return my->create_monitored_asset(issuer, symbol, precision, description, feed_lifetime_sec, minimum_feeds, broadcast);
}

signed_transaction wallet_api::update_monitored_asset(string symbol,
                                                      string description,
                                                      uint32_t feed_lifetime_sec,
                                                      uint8_t minimum_feeds,
                                                      bool broadcast /* = false */)
{
   return my->update_monitored_asset(symbol, description, feed_lifetime_sec, minimum_feeds, broadcast);
}

signed_transaction wallet_api::create_user_issued_asset(string issuer,
                                                        string symbol,
                                                        uint8_t precision,
                                                        string description,
                                                        uint64_t max_supply,
                                                        price core_exchange_rate,
                                                        bool is_exchangeable,
                                                        bool broadcast /* = false */)
{
   return my->create_user_issued_asset(issuer, symbol, precision, description, max_supply, core_exchange_rate, is_exchangeable, broadcast);
}

signed_transaction wallet_api::issue_asset(string to_account, string amount, string symbol,
                                           string memo, bool broadcast)
{
   return my->issue_asset(to_account, amount, symbol, memo, broadcast);
}

signed_transaction wallet_api::update_user_issued_asset(string symbol,
                                                        string new_issuer,
                                                        string description,
                                                        uint64_t max_supply,
                                                        price core_exchange_rate,
                                                        bool is_exchangeable,
                                                        bool broadcast /* = false */)
{
   return my->update_user_issued_asset(symbol, new_issuer, description, max_supply, core_exchange_rate, is_exchangeable, broadcast);
}

signed_transaction wallet_api::fund_asset_pools(string from,
                                                string uia_amount,
                                                string uia_symbol,
                                                string DCT_amount,
                                                string DCT_symbol,
                                                bool broadcast /* = false */)
{
   return my->fund_asset_pools(from, uia_amount, uia_symbol, DCT_amount, DCT_symbol, broadcast);
}

signed_transaction wallet_api::reserve_asset(string from,
                                             string amount,
                                             string symbol,
                                             bool broadcast /* = false */)
{
   return my->reserve_asset(from, amount, symbol, broadcast);
}

string wallet_api::price_to_dct(const string& amount, const string& asset_symbol_or_id)
{
   return my->price_to_dct(amount, asset_symbol_or_id );
}

signed_transaction wallet_api::claim_fees(string uia_amount,
                                          string uia_symbol,
                                          string dct_amount,
                                          string dct_symbol,
                                          bool broadcast /* = false */)
{
   return my->claim_fees( uia_amount, uia_symbol, dct_amount, dct_symbol, broadcast);
}

signed_transaction wallet_api::publish_asset_feed(string publishing_account,
                                                  string symbol,
                                                  price_feed feed,
                                                  bool broadcast /* = false */)
{
   return my->publish_asset_feed(publishing_account, symbol, feed, broadcast);
}

multimap<time_point_sec, price_feed> wallet_api::get_feeds_by_miner(const string& account_name_or_id,
                                                                  const uint32_t count)
{
   account_id_type account_id = get_account( account_name_or_id ).id;
   return my->_remote_db->get_feeds_by_miner( account_id, count );
}

real_supply wallet_api::get_real_supply()const
{
   return my->_remote_db->get_real_supply();
}
