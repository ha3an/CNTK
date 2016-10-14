//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//

#pragma  once

#include "CNTKLibrary.h"

namespace CNTK
{
    ///
    /// Distributed Trainer.
    ///
    class DataParallelDistributedTrainer : public DistributedTrainer
    {
    public:
        // Optional override that gets called per minibatch after finishing gradient computation but before updating model parameters
        void PreParameterUpdateCallback(const Trainer& trainer, const std::unordered_map<Variable, Value>& gradientValues) override;

        // Optional override that gets called before each minbatch during training
        void PreMinibatchCallback(const Trainer& trainer) override;

        // Optionally overridable method to get checkpoint state associated with this Distributed train method
        Dictionary GetCheckpointState() const override;

        // Optionally overridable method to restore state pertaining this distributed training method from a previous checkpoint
        void RestoreFromCheckpoint(const Dictionary& checkpoint) override;
    };
}