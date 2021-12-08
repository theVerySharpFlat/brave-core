/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/legacy_migration/rewards/legacy_rewards_migration_unblinded_payment_tokens_json_reader.h"

#include "base/json/json_reader.h"
#include "base/values.h"
#include "bat/ads/internal/legacy_migration/rewards/legacy_rewards_migration_unblinded_payment_tokens_json_reader_util.h"
#include "third_party/abseil-cpp/absl/types/optional.h"

namespace ads {
namespace rewards {
namespace JSONReader {

absl::optional<privacy::UnblindedPaymentTokenList> ReadUnblindedPaymentTokens(
    const std::string& json) {
  const absl::optional<base::Value>& value = base::JSONReader::Read(json);
  if (!value || !value->is_dict()) {
    return absl::nullopt;
  }

  const absl::optional<privacy::UnblindedPaymentTokenList>&
      unblinded_payment_tokens_optional = ParseUnblindedPaymentTokens(*value);
  if (!unblinded_payment_tokens_optional) {
    return absl::nullopt;
  }
  return unblinded_payment_tokens_optional.value();
}

}  // namespace JSONReader
}  // namespace rewards
}  // namespace ads
